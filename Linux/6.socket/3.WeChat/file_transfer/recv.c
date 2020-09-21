/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 08:44:41 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    int listener, port, fd;
    pid_t pid;
    port = atoi(argv[1]); 
    if ((listener = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }
    while (1) {
        if ((fd = accept(listener, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        } 
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            close(listener);
            recv_file(fd);
            exit(0);
        } else {
            close(fd);
        }
    }

    return 0;
}

