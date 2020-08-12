/*************************************************************************
	> File Name: common.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月08日 星期六 14时31分19秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
struct User {
    int fd;
    char name[20];
    int online;
    char real_name[20];
    char chat_name[20];
    char ip[20];
    char id[50];
};

void get_info(const char *names, struct User *user, char *ip);
char *get_conf(const char *conf, char *key);
extern char conf_value_ans[512];
int make_non_block(int fd);
int make_block(int fd);
int socket_create(int port);
int socket_connect(char *ip, int port);
#endif
