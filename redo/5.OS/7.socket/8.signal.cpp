/*************************************************************************
	> File Name: signal.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月13日 星期二 09时27分15秒
 ************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <pthread.h>
#define MAX_EVENT_NUMBER 1024
#define handle_errno(msg) \
    do {perror("msg"); exit(1); } while(0);

static int pipefd[2];

void setnonblock(int fd) {
    int flag = fcntl(fd, F_GETFL);
    assert(flag != -1);
    flag |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) < 0) {
        perror("fcntl");
    }
    return ;
}

void add_event(int epollfd, int fd, bool enable_et ) {
    struct epoll_event event;
    bzero(&event ,sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = fd;
    if (enable_et) {
        event.events |= EPOLLET;
    }
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    setnonblock(fd);
    return ;
}

void sig_handler(int sig) {
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1], (char*)&msg, 1, 0);
    errno = save_errno;
}

void add_sig(int sig) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        return 1;
    }
    const char *ip = argv[1];
    int port=  atoi(argv[2]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    if (bind(listenfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_errno("bind");
    }
    if (listen(listenfd, 5) < 0) {
        handle_errno("listen");
    }

    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(1);
    if (epollfd < 0) {
        handle_errno("epoll_create");
    }
    add_event(epollfd, listenfd, false);

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, pipefd) < 0) {
        handle_errno("socketpair");
    }
    setnonblock(pipefd[1]);
    add_event(epollfd, pipefd[0], true);

    add_sig(SIGHUP);
    add_sig(SIGCHLD);
    add_sig(SIGTERM);
    add_sig(SIGINT);
    bool stop_server = false;

    while (!stop_server) {
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
                int connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength);
                if (connfd < 0) {
                    perror("accept");
                    continue;
                }
                add_event(epollfd, connfd, true);
            } else if (sockfd == pipefd[0] && events[i].events & EPOLLIN) {
                int sig;
                char signals[1024];
                int nrecv = recv(pipefd[0], signals, sizeof(signals), 0);
                if (nrecv < 0) {
                    perror("recv");
                    continue;
                }
                if (nrecv == 0) {
                    continue;
                }
                for (int i = 0; i < nrecv; i++) {
                    switch (signals[i]) {
                        case SIGCHLD : 
                        case SIGHUP : continue;
                        case SIGTERM : 
                        case SIGINT : {
                            stop_server = true;
                        } break;
                        default : break;
                    }
                }
            } else {
                printf("something else happend\n");
            }
        }
    }
    printf("close fds\n");
    close(listenfd);
    close(epollfd);
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
