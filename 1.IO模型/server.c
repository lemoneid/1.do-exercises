/*************************************************************************
	> File Name: server.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月09日 星期日 16时12分27秒
 ************************************************************************/

#include "head.h"

void *do_chat(void *arg) {
    int fd;
    char ip[20] = {0};
    struct User user;
    fd = *(int *)arg;
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t len = sizeof(client);
    getpeername(fd, (struct sockaddr *)&client, &len);
    strcpy(ip, inet_ntoa(client.sin_addr));
    get_info("../common/names", &user, ip);
    while (1) {
        ssize_t nrecv;
        char buff[512];
        if ((nrecv = recv(fd, buff, sizeof(buff), 0)) <= 0) {
            close(fd);
            return NULL;
        }
        printf(BLUE"%s"NONE" : %s\n", user.name, buff);
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
        //多线程，内存共享，传地址，保证使用前，地址不会被修改;
        //newfd有风险，-->缓冲池,连接池; 并行
        // -->对 fd 加锁; 串行
        usleep(50);
    }

    return 0;
}
