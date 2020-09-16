/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 08:44:41 PM CST
 ************************************************************************/

#include "head.h"

struct Msg {
    char filename[512];
    int size;
    char buff[1024];
};

void recv_file(int sockfd) {
    while (1) {
        ssize_t nrecv;
        struct Msg msg;
        if ((nrecv = recv(fd, msg, sizeof(msg), 0)) <= 0) {
            close(sockfd);
            return NULL;
        }
        if ()
        
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

    while (1) {
        int newfd;
        pthread_t tid;
        if ((newfd = accept(listener, NULL, NULL)) < 0) {
            perror("accept()");
            exit(1);
        }
        pthread_create(&tid, NULL, , (void *)&newfd);
        usleep(50);
    }

    return 0;
}

