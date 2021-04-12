/*************************************************************************
	> File Name: 3.epoll.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 10时15分17秒
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
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#define MAX_EVENTS_NUMBER 1024
#define BUFFER_SIZE 10

int make_nonblock(int fd) {
    int op = fcntl(fd, F_GETFL);
    int new_op = op | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_op);
    return op;
}

void add_event(int epollfd, int fd, int enable_et) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if (enable_et) {
        event.events |= EPOLLET;
    }
    if (epoll_ctl(epollfd, fd, EPOLL_CTL_ADD, &event) < 0) {
        perror("epoll_ctl");
    }
    make_nonblock(fd);
    return ;
}

void lt(struct epoll_event *events, int number, int epollfd, int listenfd) {
    char buf[BUFFER_SIZE] = {0};
    for (int i = 0; i < number; i++) {
        int sockfd = events[i].data.fd;
        if (sockfd == listenfd) {
            struct sockaddr_in client_address;
            socklen_t client_addrlength = sizeof(struct sockaddr_in);
            int connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength);
            
            add_event(epollfd, connfd, 0);
        } else if (events[i].events & EPOLLIN) {
            printf("event trigger once\n");
            memset(buf, 0, sizeof(buf));
            int nrecv = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
            if (nrecv <= 0) {
                close(sockfd);
                continue;
            }
            printf("get %d bytes of connent : %s\n", nrecv, buf);
        } else {
            printf("something else happening\n");
        }
    }
}

void et(struct epoll_event *events, int number, int epollfd, int listenfd) {
    char buf[BUFFER_SIZE] = {0};
    for (int i = 0; i < number; i++) {
        int sockfd = events[i].data.fd;
        if (sockfd == listenfd) {
            struct sockaddr_in client_address;
            socklen_t client_addrlength = sizeof(struct sockaddr_in);
            int connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength);
            
            add_event(epollfd, connfd, 0);
        } else if (events[i].events & EPOLLIN) {
            printf("event trigger once\n");
            while (1) {
                memset(buf, 0, sizeof(buf));
                int nrecv = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
                if (nrecv < 0) {
                    if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                        printf("read later\n");
                        break;
                    }
                    close(sockfd);
                    continue;
                } else if (nrecv == 0) {
                    close(sockfd);
                } else {
                    printf("get %d bytes of connent : %s\n", nrecv, buf);
                }
            }
        } else {
            printf("something else happening\n");
        }
    }
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        fprintf(stderr, "Usage : %s ip_address port_number\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int listenfd, val = 1, epollfd;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = port;
    address.sin_addr.s_addr = inet_addr("0.0.0.0");
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
    }
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
        perror("setsockopt");
    }
    if (bind(listenfd, (struct sockaddr *)&address, sizeof(struct sockaddr_in)) < 0) {
        perror("bind");
    }

    if (listen(listenfd, 5) < 0) {
        perror("listenfd");
    }

    struct epoll_event  events[MAX_EVENTS_NUMBER];
    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create");
    }
    add_event(epollfd, listenfd, 1);

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS_NUMBER, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            break;
        }
        lt(events, nfds, epollfd, listenfd);
        //et(events, nfds, epollfd, listenfd);
    }
    close(epollfd);
    close(listenfd);
    

    return 0;
}
