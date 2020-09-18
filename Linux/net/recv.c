/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 08:44:41 PM CST
 ************************************************************************/

#include "head.h"

struct Msg {
    char filename[512];
    long long size;
    char buff[4096];
};

void recv_file(int sockfd) {
    while (1) {
        ssize_t nrecv;
        struct Msg msg;
        if ((nrecv = recv(fd, msg, sizeof(msg), 0)) <= 0) {
            close(sockfd);
            return NULL;
        }
        printf("%s", msg.buff);
        memset(msg.buff, 0, sizeof(msg.buff));
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    
    int listener, port;
    port = atoi(argv[1]); 
    if ((listener = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }

    recv_file(listener);
    return 0;
}

