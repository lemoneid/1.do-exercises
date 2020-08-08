/*************************************************************************
	> File Name: chat.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 09时20分45秒
 ************************************************************************/

#ifndef _CHAT_H
#define _CHAT_H

struct Message {
    char name[20];
    char msg[1024];
    pid_t pid;
    pthread_mutex_t mutex;
};

#endif
