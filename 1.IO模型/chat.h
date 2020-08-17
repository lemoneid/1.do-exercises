/*************************************************************************
	> File Name: chat.h
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 16 Aug 2020 10:50:32 AM CST
 ************************************************************************/

#ifndef _CHAT_H
#define _CHAT_H

#define MAXUSER 100

struct User {
    char name[20];
    char chat_name[20];
    char real_name[20];
    int flag;//可心跳的次数，默认设置为10
    char ip[20];
    int fd;
    int online;//1在线，0不在线
};

#define CHAT_SYN 0x01
#define CHAT_FIN 0x02
#define CHAT_ACK 0x04
#define CHAT_HEART 0x08
#define CHAT_PRI 0x10
#define CHAT_PUB 0x20
#define CHAT_FUNC 0x40
#define CHAT_SYS 0x80
#define CHAT_NAK 0x100

#define FUNC_CHECK_ONLINE 0x01
#define FUNC_CHANGE_NAME 0x02
struct ChatMsg {
    int type;
    int opt;
    char name[20];
    char msg[1024];
};
#endif
