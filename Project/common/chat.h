/*************************************************************************
	> File Name: chat.h
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 19 Aug 2020 02:29:50 PM CST
 ************************************************************************/

#ifndef _CHAT_H
#define _CHAT_H
#define MAXUSER 100
#define MAXEVENTS 10
#define THREADNUM 5
//#include "head.h"

void add_event(int epollfd, int fd, int events, struct User *user);
void del_event(int epollfd, struct User *user);
int find_sub(struct User *users, int max);
int do_login(struct User *user, struct ChatMsg *msg);
void *heart_beat(void *arg);

#endif
