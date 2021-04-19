/*************************************************************************
	> File Name: 1.close-connect.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月13日 星期二 16时20分36秒
 ************************************************************************/

#include "head.h"
#include "1.timer-list.h"
#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

static int pipefd[2];
static sort_timer_list timer_list;
static int epollfd = 0;

int setnonblock(int fd) {
    int option = fcntl(fd, F_GETFL);
    if (fcntl(fd, F_SETFL, option | O_NONBLOCK) < 0) {
        perror("fcntl");
    }
    return option;
}

void add_event(int epollfd, int fd, bool enable_et) {
    struct epoll_event event;
    bzero(&event, sizeof(event));
    event.data.fd = fd;
    event.events = EPOLLIN;
    if (enable_et) {
        event.events |= EPOLLET;
    }
    setnonblock(fd);
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_ctl");
    }
    return ;
}

void sig_handler(int sig) {
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1], (char *)&msg, 1, 0);
    errno = save_errno;
    return ;
}

void add_sig(int sig) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
}

void timer_handler() {
    //定时处理任务
    timer_list.tick();
    //一次alarm调用触发一次SIGALRM,所以重新定时，以不断出发SIGALRM
    alarm(TIMESLOT);
}

void cb_func(client_data *user_data) {
    if (epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->sockfd, 0) < 0) {
        perror("epoll_ctl");
    }
    assert(user_data);
    close(user_data->sockfd);
    printf("close fd %d\n", user_data->sockfd);
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    int ret = bind(listenfd, (struct sockaddr *)&server_address, sizeof(server_address));
    assert(ret != -1);
    ret = listen(listenfd, 5);
    assert(ret != -1);
    
    struct epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(1);
    assert(epollfd >= 0);
    add_event(epollfd, listenfd, false);

    ret = socketpair(AF_UNIX, SOCK_STREAM, 0, pipefd);
    assert(ret = -1);
    setnonblock(pipefd[1]);
    add_event(epollfd, pipefd[0], true);

    add_sig(SIGALRM);
    add_sig(SIGTERM);
    bool stop_server = false;
    
    struct client_data *users = new client_data[FD_LIMIT];
    bool timeout = false;

    while (!stop_server) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if (nfds < 0 && (errno != EINTR)) {
            perror("epoll_wait");
            break;
        }
        for (int i = 0; i < nfds; i++) {
            int sockfd = events[i].data.fd;
            if (sockfd == listenfd) {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(epollfd, (struct sockaddr *)&client_address, &client_addrlength);
                if (connfd < 0) {
                    perror("accept");
                    continue;
                }
                add_event(epollfd, connfd, true);
                users[connfd].address = client_address;
                users[connfd].sockfd = connfd;
                //timer
                util_timer * timer = new util_timer;
                timer->user_data = &users[connfd];
                timer->cb_func = cb_func;
                time_t cur = time(NULL);
                timer->expire = cur + 3 * TIMESLOT;
                users[connfd].timer = timer;
                timer_list.add_timer(timer);
            } else if (sockfd == pipefd[0] && events[i].events & EPOLLIN) {
                int sig;
                char signals[1024];
                int nrecv = recv(sockfd, signals, sizeof(signals), 0);
                if (nrecv == -1) {
                    // handle error
                    continue;
                } else if (nrecv == 0) {
                    continue;
                } else {
                    for (int i = 0; i < nrecv; i++) {
                        switch (signals[i]) {
                            case SIGALRM : {
                                timeout = true;
                            }  break;
                            case SIGTERM : {
                                stop_server = true;
                            } break;
                            default : break;
                        }
                    }
                }
            } else if (events[i].events & EPOLLIN) {
                memset(users[sockfd].buf, 0, sizeof(users[sockfd].buf));
                int nrecv = recv(sockfd, users[sockfd].buf, sizeof(users[sockfd].buf), 0);
                printf("get %d bytes of client data %s from %d\n", nrecv, users[sockfd].buf, sockfd);
                util_timer *timer = users[sockfd].timer;
                if (nrecv < 0) {
                    if (errno != EAGAIN) {
                        cb_func(&users[sockfd]);
                        if (timer) {
                            timer_list.del_timer(timer);
                        }
                    }
                } else if (nrecv == 0) {
                    cb_func(&users[sockfd]);
                    if (timer) {
                        timer_list.del_timer(timer);
                    }
                } else {
                    if (timer) {
                        time_t cur = time(NULL);
                        timer->expire = cur + 3 * TIMESLOT;
                        printf("adjust timer once\n");
                        timer_list.adjust_timer(timer);
                    }
                } 
            } else {
                printf("something else happened\n");
            }
        }
        if (timeout) {
            timer_handler();
            timeout = false;
        }
    }

    close(listenfd);
    close(pipefd[0]);
    close(pipefd[1]);
    delete [] users;
    return 0;
}
