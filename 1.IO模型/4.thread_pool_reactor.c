/*************************************************************************
> File Name: 3.one_thread_reactor.c
> Author: suyelu 
> Mail: suyelu@126.com
> Created Time: Wed 12 Aug 2020 04:10:08 PM CST
************************************************************************/

#include "head.h"
#include "./thread_pool/thread_pool.h"
#include "./chat.h"

#define MAXTHREAD 4 
#define MAXQUEUE 20
#define MAXEVENTS 10

#define SUCCESS "Welcome to login! please start to chat\n"
#define FAILURE "Sorry! your name have login\n"
struct User user[MAXUSER];
struct Anon anons[MAXUSER];
int epollfd;

void *Stop(int signum) {
    struct ChatMsg cm;
    memset(&cm, 0, sizeof(cm));
    cm.type |= CHAT_FIN;
    for (int i = 0; i < MAXUSER; ++i) {
        if (user[i].online == 1)
            send(user[i].fd, &cm, sizeof(cm), 0);
    }
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    int server_listen, sockfd, port;
    int fd[MAXUSER] = {0};
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }
    //task_queue
    struct task_queue taskQueue;
    task_queue_init(&taskQueue, MAXQUEUE);

    pthread_t *tid = (pthread_t *)calloc(MAXTHREAD, sizeof(pthread_t));

    for (int i = 0; i < MAXTHREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)&taskQueue);
    }
    //heart
    pthread_t tid_heart;
    pthread_create(&tid_heart, NULL, thread_heart, (void *)(NULL));

    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create()");
        exit(1);
    }

    struct epoll_event ev, events[MAXEVENTS];

    ev.data.fd = server_listen;
    ev.events = EPOLLIN;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0) {
        perror("epoll_ctl()");
        exit(1);
    }

    // init_anon
    init_anon();

    for (int i = 0; i < 100; ++i) {
        printf("%s\n", anons[i].name);
    }

    // ctrl + c
    signal(SIGINT, (void *)Stop);

    //epoll

    while (1) {
        //sleep(1);
        int nfds = epoll_wait(epollfd, events, MAXEVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            exit(1);
        }

        //DBG(YELLOW"<Debg>"NONE" : After wait nfds = %d\n", nfds);
        for (int i = 0; i < nfds; ++i) {
            if (events[i].data.fd == server_listen  && (events[i].events & EPOLLIN)) {
                if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
                    perror("accept()");
                    exit(1);
                }
                
                do {
                    //设置timeout
                    socklen_t optlen = sizeof(struct timeval);
                    struct timeval tv;
                    tv.tv_sec = 0;
                    tv.tv_usec = 50 * 1000;
                    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, optlen) < 0){
                        perror("setsockopt(); epoll");
                    }

                    struct ChatMsg syn;
                    memset(&syn, 0, sizeof(syn));
                    if (recv(sockfd, &syn, sizeof(syn), 0) <= 0) {
                        DBG(YELLOW"<fd = %d>"NONE" : timeout\n", sockfd);
                        perror("recv() : server");
                        break;
                    }
                    DBG(YELLOW"<Debg>"NONE" :  recv name = %s, msg = %s\n", syn.name, syn.msg);
                    if (search_name(syn.name) == -1 && (syn.type & CHAT_SYN)) {
                        syn.type |= CHAT_ACK;
                        strcpy(syn.msg, SUCCESS);
                        send(sockfd, &syn, sizeof(syn), 0);
                    } else {
                        //memset(&syn, 0, sizeof(syn));
                        syn.type |= CHAT_NAK;
                        strcpy(syn.msg, FAILURE);
                        send(sockfd, &syn, sizeof(syn), 0);
                        break;
                    }

                    // add-user
                    user[sockfd].fd = sockfd;
                    strcpy(user[sockfd].real_name, syn.name);
                    user[sockfd].flag = 10;
                    struct sockaddr_in client;
                    bzero(&client, sizeof(client));
                    socklen_t len = sizeof(client);
                    getpeername(sockfd, (struct sockaddr *)&client, &len);
                    strcpy(user[sockfd].ip, inet_ntoa(client.sin_addr));
                    user[sockfd].online = 1;

                    //DBG(YELLOW"<fd = %d>"NONE" : server_listen, fd= %d\n", sockfd, );

                    fd[sockfd] = sockfd;
                    ev.events = EPOLLIN | EPOLLET;
                    ev.data.fd = sockfd;
                    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
                        perror("epoll_ctl()");
                        exit(1);
                    }
                } while (0);
            } else {
                if (events[i].events & EPOLLIN) {
                    //DBG(YELLOW"<main>"NONE" : fds = %d; Push!\n", events[i].data.fd);
                    task_queue_push(&taskQueue, events[i].data.fd);
            }
        }
    }
}
    return 0;
}
