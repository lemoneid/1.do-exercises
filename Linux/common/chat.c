/*************************************************************************
	> File Name: common/chat.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 19 Aug 2020 02:47:29 PM CST
 ************************************************************************/

#include "head.h"

extern struct User *users;
extern int epollfd;
extern int maxfd;

void add_event(int epollfd, int fd, int events, struct User *user) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.ptr = (void *)user;
    DBG(PINK"Main Reactor"NONE " : adding %s to main reacator\n", user->name);

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        perror("epoll_ctl()");
        exit(1);
    }

}

void del_event(int epollfd, struct User *user) {
    epoll_ctl(epollfd, EPOLL_CTL_DEL, user->fd, NULL);
    DBG(PINK"Main Reactor"NONE " : deling %s to main reacator\n", user->name);
}

int find_sub(struct User *users, int max) {
    for (int i = 1; i < max; ++i) {
        if (!users[i].online) {
            return i;
        }
    }
    return -1;
}

int do_login(struct User *user, struct ChatMsg *msg) {
    int online = 0;
    for (int i = 0; i <= maxfd; ++i) {
        if (users[i].online && !strcmp(msg->name, usesr[i].name)) {
            online = 1;
        }
    }
    if (online) {
        DBG(YELLOW"Login Error"NONE" : %s is already online\n", msg.name);
        sprintf(msg->msg, "%s is already online", msg->name);
        msg->type |= CHAT_NAK;
        user->online = 0;
        send(user->fd, (void *)msg, sizeof(msg), 0);
        close(user->fd);
        del_event(epollfd, user);
        return 1;
    } else {
        DBG(L_GREEN"Login Success"NONE" : %s login Success\n", msg.name);
        sprintf(msg->msg, "%s, you login Success!", msg->name);
        msg->type |= CHAT_ACK;
        send(user->fd, msg, sizeof(msg), 0);
        user->online = 1;
        user->flag = 10;
        strcpy(user->name, msg->name);
        /*
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        getpeername(user->fd, (struct sockaddr *)&client, &len);
        strcpy(user->ip, inet_ntoa(client.sin_addr));
        get_info();
        */
        return 0;
    }
}

void *heart_beat(void *arg) {
    struct ChatMsg msg;
    msg,type |= CHAT_HEART;
    while (1) {
        sleep(5);
        for (int i = 1; i <= maxfd; ++i) {
            if (user[i].online == 1) {
                send(users[i].fd, &msg, sizeof(msg), 0);
                if (--user[i].flag == 0) {
                    DBG("Heart Beart"NONE" : %s is offine by heart_beat\n", users[i].name);
                    del_event(epollfd, &users[i]);
                    close(user[i].fd);
                    users[i].online = 0;
                }
            }
        }
    }
}

void *client_recv(void *arg) {
    struct ChatMsg msg;
    int sockfd = *arg;
    while (1) {
        bzero(&msg, sizeof(msg));
        if (recv(sockfd, (void *)&msg, sizeof(msg), 0) < 0) {
            perror("client_recv");
            exit(1);
        }
        if (msg.type & CHAT_PUB) {
            printf(BLUE"%s"NONE " : %s\n", msg.name, msg.msg);
        } else if (msg.type & CHAT_HEART) {
            msg.type = CHAT_ACK;
            send(sockfd, (void *)&msg, sizeof(msg), 0);
        } else if (msg.type & CHAT_PRI) {
            printf(BLUE"%s"GREEN"*"NONE " : %s\n", msg.name, msg.msg);
        } else if (msg.type & CHAT_SYS) {
            printf(L_PINK"%s"NONE" : %s\n", "Server INfo", msg.msg);
        } else if (msg.type & (CHAT_FUNC_! | CHAT_FIN)) {
            printf(GREEN"\nBye!\n"NONE);
            exit(1);
        }
    }
}
