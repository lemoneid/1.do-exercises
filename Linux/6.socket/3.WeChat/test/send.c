/*************************************************************************
	> File Name: send.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 24 Sep 2020 08:12:40 PM CST
 ************************************************************************/

#include "datatype.h"
#include "head.h"


void send_file(char *filename, int sockfd) {
    struct FileMsg msg;
    memset(&msg, 0, sizeof(msg));
    FILE *fp = NULL;
    size_t nread;
    if ((fp = fopen(filename, "rb")) == NULL) {
        handle_error("fopen");
    }
    fseek(fp, 0L, SEEK_END);
    msg.size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    strcpy(msg.name, strrchr(filename, '/'));
    while ((nread = fread(msg.buff, sizeof(msg.buff), 1, fp))) {
        send(sockfd, &msg, sizeof(msg), 0);
        memset(msg.buff, 0, sizeof(msg.buff));
    }
    return ;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "%s Usage : ip/port/filename\n", argv[0]);
    }

    char ip[20] = {0}, filename[1024] = {0}, buff[1024] = {0};
    int port, sockfd;
    port = atoi(argv[2]);
    strcpy(ip, argv[1]);
    strcpy(filename, argv[3]);
    if ((sockfd = socket_connect(ip, port)) < 0) {
        handle_error("socket_connect()");
    }
    
    while (1) {
        scanf("%[^\n]s", buff);
        getchar();
        if (!strncmp("send ", buff, 5)) {
            strcpy(filename, buff + 5);
            send_file(filename, sockfd);
        } else {
            printf("the commmand is error\n");
        }
    }

    return 0;
}


