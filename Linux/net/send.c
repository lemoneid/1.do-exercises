/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月16日 星期三 20时16分10秒
 ************************************************************************/

#include "head.h"

struct Msg {
    char filename[512];
    long long size;
    char buff[4096];
};

void send_file(const char *filename,FILE *fp,int sockfd) {
    struct Msg msg;
    int nread;
    memset(&msg, 0, sizeof(msg));
    strcpy(msg.filename, filename);
    while ((nread = fread(msg.buff, 1, sizeof(msg.buff), fp)) > 0) {
        send(sockfd, &msg, sizeof(msg), 0);
        printf("%s", msg.buff);
        memset(msg.buff, 0, sizeof(msg.buff));
    }
    recv(sockfd, &msg, sizeof(msg), 0);
    return 0;
}

void recv_file(int sockfd) {
        ssize_t nrecv;
        struct Msg msg;
        int first = 1;
        FILE *fp = NULL;
        while ((nrecv = recv(sockfd, &msg, sizeof(msg), 0)) > 0) {
            if (first) {
                fp = fopen(msg.filename, "wb");
            }
            fwrite(msg.buff, nrecv, 1, fp);
        }
}


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

    FILE *fp = NULL;
    char *path = "./recv.c";
    char *filename = "send";

    if ((fp = fopen(path, "r")) == NULL) {
        printf("fopen error\n");
        perror("fopen()");
        exit(1);
    }
    send_file(filename, fp, sockfd);
    return 0;
}
