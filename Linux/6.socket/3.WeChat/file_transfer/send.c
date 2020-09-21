/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月16日 星期三 20时16分10秒
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    if (argc != 3){
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    int sockfd, port;
    char buff[1024] = {0}, name[1024] = {0}, ip[20] = {0};
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect()");
        exit(1);
    }
    while (1) {
        scanf("%[^\n]s", buff);
        getchar();
        if (!strncmp("send ", buff, 5)) {
            strcpy(name, buff + 5);
        } else {
            fprintf(stderr, "invalid command!");
            continue;
        }
        send_file(name, sockfd);

    }
    close(sockfd);
    return 0;
}
