/*************************************************************************
	> File Name: file.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 08:44:41 PM CST
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
        ssize_t recv_size = 0, total_size = 0;
        struct FileMsg packet_t, packet;
        int packet_size = sizeof(struct FileMsg);
        int first  = 1, offset = 0;
        while ((recv_size = recv(sockfd, &packet, sizeof(packet), 0)) > 0) {
            if (first) {
                fp = fopen(msg.filename, "wb");
            }
            first = 0;
            if (offset + recv_size == packet_size) {
                fwrite(packet.buff, sizeof(packet.buff), 1, fp);
                printf(GREEN"整包"NONE":packet_size");
                offset = 0;
            } else if (offset + recv_size < packet_size) {
                offset += recv_size; 
                memcpy();
            }
        }
}


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
    whlie (1) {
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

