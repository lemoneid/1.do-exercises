/*************************************************************************
	> File Name: 0.one_thread.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 08时09分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>      
#include <sys/socket.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }

    int server_listen, sockfd, port;
    port = atoi(argv[1]);

    if ((server_listen = sock_create(port)) < 0) {
        perror("sock_create");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client;
        char buff[512];
        socklen_t len = sizeof(client);
        if ((sockfd = accept(server_listen, (struct sockaddr *)(&client), &len)) < 0) {
            perror("accept()");
            exit(1);
        }
        read(sockfd, buff, sizeof(buff));
        printf("<buff> : %s", buff); 
        close(sockfd);
   }

    return 0;
}
