/*************************************************************************
	> File Name: server.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月09日 星期日 16时12分27秒
 ************************************************************************/

#include "head.h"

void *do_chat(void *arg) {
    int fd;
    fd = *(int *)arg;
    while (1) {
        ssize_t nrecv;
        char buff[512];
        if ((nrecv = recv(fd, buff, sizeof(buff), 0)) <= 0) {
            close(fd);
            return NULL;
        }
        printf("Recv : %s\n", buff);
        send(fd, buff, strlen(buff), 0);
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
        pthread_create(&tid, NULL, do_chat, (void *)&newfd);
    }

    return 0;
}
