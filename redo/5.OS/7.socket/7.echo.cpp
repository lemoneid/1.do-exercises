/*************************************************************************
	> File Name: 7.echo.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 21时02分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#define MAX_EVENT_NUMBER 1024
#define TCP_BUFFER_SIZE 512
#define UDP_BUFFER_SIZE 1024

void setnonblock(int fd) {
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return ;
}

void add_event(int epollfd, int fd, bool enable_et) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    if (enable_et) event.events |= EPOLLET;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    setnonblock(fd);
    return ;
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    int ret = bind(listenfd, (struct sockaddr *)&address, sizeof(address)); 
    assert(ret != -1);
    ret = listen(listenfd, 5);
    assert(ret != -1);

    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    int udpfd = socket(AF_INET, SOCK_DGRAM, 0);
    assert(udpfd >= 0);
    ret = bind(udpfd, (struct sockaddr *)&address, sizeof(address)); 
    assert(ret != -1);

    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(1);
    assert(epollfd != -1);
    add_event(epollfd, listenfd, false);
    add_event(epollfd, udpfd, false);

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
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
                if (connfd < 0) {
                    perror("accept");
                    continue;
                }
                add_event(epollfd, connfd, true);
            } else if (sockfd == udpfd) {
                char buf[UDP_BUFFER_SIZE]; 
                memset(buf, 0, sizeof(buf));
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int nrecv = recvfrom(udpfd, buf, UDP_BUFFER_SIZE - 1, 0, (struct sockaddr*)&client_address, &client_addrlength);
                if (nrecv > 0) {
                    sendto(udpfd, buf, nrecv, 0, (struct sockaddr*)&client_address, client_addrlength);
                }
            } else if (events[i].events & EPOLLIN) {
                char buf[TCP_BUFFER_SIZE];
                while (1) {
                    memset(buf, 0, sizeof(TCP_BUFFER_SIZE));
                    int nrecv = recv(sockfd, buf, TCP_BUFFER_SIZE - 1, 0);
                    if (nrecv < 0) {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                            break;
                        }
                        close(sockfd);
                        break;
                    } else if (nrecv == 0) {
                        close(sockfd);
                        break;
                    } else {
                        send(sockfd, buf, nrecv, 0);
                    }
                }
            } else {
                printf("something else happened\n");
            }
        }
    }

    close(listenfd);
    close(udpfd);


    return 0;
}
