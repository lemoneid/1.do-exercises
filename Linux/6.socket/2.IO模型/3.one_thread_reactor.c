/*************************************************************************
> File Name: test.c
> Author: weier 
> Mail: 1931248856@qq.com 
> Created Time: Wed 12 Aug 2020 04:43:41 PM CST
************************************************************************/

#include "head.h"
#define MAX 10
#define MAXUSER 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    int server_listen, sockfd, port, epollfd;
    ssize_t nrecv;
    // 0 有问题,fd自动分配是尽可能小的
    int fd[MAXUSER] = {0};
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }

    //epoll实例， ->反应堆
    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create()");
        exit(1);
    }

    struct epoll_event ev, events[MAX];

    ev.data.fd = server_listen;
    ev.events = EPOLLIN;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0) {
        perror("epoll_ctl()");
        exit(1);
    }

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; ++i) {
            if (events[i].data.fd == server_listen  && (events[i].events & EPOLLIN)) {
                if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
                    perror("accept()");
                    exit(1);
                }
                fd[sockfd] = sockfd;
                ev.events = EPOLLIN | EPOLLRDHUP;
                ev.data.fd = sockfd;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
                    perror("epoll_ctl()");
                    exit(1);
                }
            } else {
                if (events[i].events & EPOLLRDHUP) {
                    if (epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, NULL) < 0) {
                        perror("epoll_ctl()");
                        exit(1);
                    }
                    printf(GREEN"<data.fd>"NONE" = %d is logout", events[i].data.fd);
                    close(events[i].data.fd);
                } 
                if (events[i].events & EPOLLIN) {
                    char buff[512] = {0};
                    nrecv = recv(events[i].data.fd, buff, sizeof(buff), 0);
                    // nrecv == 0 socket断开, man-RETURNVALUE
                    if (nrecv < 0) {
                        perror("recv()");
                        exit(1);
                    } else if (nrecv == 0) {
                        printf(RED"<fd = %d>"NONE" is logout\n", events[i].data.fd);
                        if (epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, NULL) < 0) {
                            perror("epoll_ctl()");
                            exit(1);
                        }
                        close(events[i].data.fd);
                    } else {
                        printf("recv : fd = %d, %s\n", events[i].data.fd,buff);
                    }
                } 
                // TCP 对端关闭，如何感知
            }
        }
    }

    close(server_listen);
    return 0;
}
