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
    memset(&msg, 0, sizeof(msg));
    strcpy(msg.filename, filename);
    while (fgets(msg.buff, sizeof(msg.buff), fp) != NULL) {
        send(sockfd, &msg, sizeof(msg), 0);
        memset(msg.buff, 0, sizeof(msg.buff));
    }
}

void recv_file(int sockfd) {
    while (1) {
        ssize_t nrecv;
        struct Msg msg;
        if ((nrecv = recv(sockfd, &msg, sizeof(msg), 0)) <= 0) {
            close(sockfd);
            return NULL;
        }
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

    if ((fp = fopen(path, "ab")) == NULL) {
        printf("fopen error\n");
        perror("fopen()");
        exit(1);
    }
    send_file(filename, fp, sockfd);
    close(sockfd);
    fclose(fp);
    return 0;
}
