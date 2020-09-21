/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月16日 星期三 20时16分10秒
 ************************************************************************/

#include "head.h"

void send_file(const char *filename,FILE *fp,int sockfd) {
    FILE *fp = NULL;
    size_t nread;
    struct FileMsg filemsg;
    char *p = NULL;
    if ((fp = fopen(filename, "rb")) == NULL) {
        perror("fopen");
        return ;
    }
    fseek(fp, 0L, SEEK_END);
    filmsg.size = ftell(fp);
    strcpy(filmsg.name, (p = strrchr(filename, '/') ? p + 1 : filename));
    fseek(fp, 0L, SEEK_SET);
    while ((nread = fread(filemsg.buff, 1, sizeof(filemsg.buff)))) {
        send(sockfd, (void*)&filemsg, sizeof(filemsg), 0);
        memset(filemsg.buff, 0, sizeof(filemsg.buff));
    }
    return ;
}

void recv_file(int sockfd) {
        ssize_t recv_size, total_size = 0;
        struct FileMsg packet_t, packet;
        int packet_size = sizeof(struct FileMsg);
        int first  = 1, offset = 0;
        while ((recv_size = recv(sockfd, &msg, sizeof(msg), 0)) > 0) {
            if (first) {
                fp = fopen(msg.filename, "wb");
            }
            first = 0;
            fwrite(msg.buff, nrecv, 1, fp);
            if (offset + recv_size == pack_size) {
                
            } else if () {
                
            } else {

            }
            
        }
}


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
        if (!strncmp("send ", buff + 5)) {
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
