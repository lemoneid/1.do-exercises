/*************************************************************************
    > File Name: 4.epolloneshot.c
    > Author: yanzhiwei
    > Mail: 1931248856@qq.com
    > Created Time: 2021年04月12日 星期一 13时10分04秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <inttypes.h>
#include <errno.h>
#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10

typedef struct Data {
    int epollfd, sockfd;
} Data;

void make_nonblock(int fd) {
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return ;
}

void add_event(int epollfd, int fd, int oneshot) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    if (oneshot) event.events |= EPOLLONESHOT;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    make_nonblock(fd);
    return ;
}

void reset_oneshot(int epollfd, int fd) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    if (epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    return ;
}

void *worker(void *arg) {
    int sockfd = ((Data *)arg)->sockfd;
    int epollfd = ((Data *)arg)->epollfd;
    printf("start new thread to recv data on fd : %d\n", sockfd);
    char buf[BUFFER_SIZE];
    while (1) {
        memset(buf, 0, sizeof(buf));
        int nrecv = recv(sockfd, buf, sizeof(buf) - 1, 0);
        if (nrecv == 0) {
            close(sockfd);
            printf("foreiner closed the connection\n");
            break;
        } else if (nrecv < 0) {
            if (errno = EAGAIN) {
                reset_oneshot(epollfd, sockfd);
                printf("read later\n");
                break;
            }
        } else {
            printf("get %d bytes content : %s\n", nrecv, buf);
            sleep(5);
        }
    }
    printf("end thread recv data on fd : %d\n", sockfd);
}


int main(int argc, char *argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usaage : %s ip port\n", argv[0]);
        exit(1);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int listenfd, val = 1;

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
    }
    
    if (setsockopt(AF_INET, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
        perror("setsockopt");
    }

    if (bind(listenfd, (struct sockaddr *)&address, sizeof(struct sockaddr_in)) < 0) {
        perror("bind");
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
    }
    
    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd;
    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create");
    }

    add_event(epollfd, listenfd, 0);

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            break;
        }
        for (int i = 0; i < nfds; i++) {
            int sockfd = events[i].data.fd;
            if (sockfd == listenfd) {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(struct sockaddr_in);
                int connfd;
                if ((connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength)) < 0) {
                    perror("accept");
                }
                add_event(epollfd, connfd, 1);
            } else if (events[i].events & EPOLLIN) {
                pthread_t tid;
                Data new_worker;
                new_worker.epollfd = epollfd;
                new_worker.sockfd = sockfd;
                pthread_create(&tid, NULL, do_work, (void *)&new_worker);
            } else {
                printf("something else happened\n");
            }
        }
    }
    close(listenfd);
    close(epollfd);
    return 0;
}
