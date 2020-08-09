/*************************************************************************
	> File Name: server.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月09日 星期日 16时12分27秒
 ************************************************************************/

#include "head.h"


int main(int argc, char **argv) {
    if (argc != 3){
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    
    int sockfd, port;
    char ip[20] = {0};
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);

    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect()");
        exit(1);
    }

    while (1) {
        char buff[512] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        send(sockfd, buff, strlen(buff), 0);
        recv(sockfd, buff, strlen(buff), 0);
        printf("Server : %s\n", buff);
    }

    return 0;
}
