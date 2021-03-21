/*************************************************************************
	> File Name: common.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月18日 星期四 22时25分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int make_non_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl()");
        return -1;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, flag);
    return 0;
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl()");
        return -1;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, flag);
    return 0;
}

int socket_create(int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
       return -1; 
    } 
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htos(port);
    server.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (bind(sockfd, (struct socket_addr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    if (listen(sockfd, 10) < 0) {
        return -1;
    }

    return sockfd;
}

int socket_connect(const char *ip, int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if ((connect(sockfd, (struct sockaddr *)&server, sizeof(server))) < 0) {
        return -1;
    }
    return sockfd;
}

