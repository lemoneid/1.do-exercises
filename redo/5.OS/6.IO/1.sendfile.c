/*************************************************************************
	> File Name: 1.sendfile.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月07日 星期三 18时55分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <assert.h>
#include <arpa/inet.h>

#define hand_error(msg) {\
    do { perror(msg); exit(EXIT_FAILURE); } while (0);\
}\

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage : %s [ip:port:file_name]\n", argv[0]);
        exit(1);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    const char *file_name = argv[3];
    int filefd;
    int sockfd;
    struct stat stat_buf;
    
    if ((filefd = open(file_name, O_RDONLY)) < 0) {
        hand_error("open");
    }

    if (fstat(filefd, &stat_buf) < 0) {
        hand_error("fstat");
    }

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr("0.0.0.0");
    socklen_t len = sizeof(address);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        hand_error("socket");
    }

    int val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
        hand_error("setsockopt");
    }

    if (bind(sockfd, (struct sockaddr *)&address, len) < 0) {
        hand_error("bind");
    }

    if (listen(sockfd, 5) < 0) {
        hand_error("listen");
    }

    struct sockaddr client;
    socklen_t client_addrlength = sizeof(client);
    int connfd;

    if ((connfd = accept(sockfd, (struct sockaddr *)&client, &client_addrlength)) < 0) {
        hand_error("accept");
    }

    sendfile(connfd, filefd, NULL, stat_buf.st_size);
    close(connfd);
    close(sockfd);
    close(filefd);
    return 0;
}
