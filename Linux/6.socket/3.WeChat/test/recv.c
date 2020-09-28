/*************************************************************************
	> File Name: recv.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月25日 星期五 08时34分15秒
 ************************************************************************/

#include "head.h"
#include "datatype.h"

void recv_file(int fd) {
    struct FileMsg packet, packet_t;
    int packet_size = sizeof(struct FileMsg);
    size_t nrecv, nwrite;
    size_t offset = 0, total_size = 0;
    FILE *fp = NULL;
    int flag = 0;
    memset(&packet, 0, sizeof(packet));
    memset(&packet_t, 0, sizeof(packet_t));

    while (1) {
        memset(&packet, 0, sizeof(packet));
        if (offset) {
            memcpy(&packet, &packet_t, offset);
        }
        memset(&packet_t, 0, sizeof(packet_t));

        while(nrecv = recv(fd, &packet_t, sizeof(packet_t), 0)) {
            if (offset + nrecv == packet_size) {
                memcpy((char *)&packet + offset, &packet_t, nrecv);
                offset = 0;
                printf(GREEN"It is a 整包\n"NONE);
                break;
            }
            if (offset + nrecv < packet_size) {
                memcpy((char *)&packet + offset, &packet_t, nrecv);
                offset += nrecv;
                printf(PINK"It is a 拆包\n"NONE);
            }
            if (offset + nrecv > packet_size) {
                size_t need = packet_size - offset;
                memcpy((char *)&packet + offset, &packet_t, need);
                offset = nrecv - need;
                printf(BLUE"It is a 粘包\n"NONE);
                break;
            }
        }
        if (!flag) {
            char filename[10124] = {0};
            sprintf(filename, "./data/%s", packet.name);
            if ((fp =  fopen(filename, "wb")) == NULL) {
                handle_error("fopen()");
            }
            printf(RED"the filename %s is start\n"NONE, packet.name);
        }
        flag = 1;
        if (packet.size - total_size >= sizeof(packet.buff)) {
            nwrite = fwrite(packet.buff, 1, sizeof(packet.buff), fp);
        } else {
            nwrite = fwrite(packet.buff, 1, packet.size - total_size, fp);
        }
        total_size += nwrite;
        if (total_size >= packet.size) {
            printf(RED"the file is finished\n"NONE);
            return ;
        }
        
    }

}


int main(int argc, char **argv) {
    if (argc != 2){
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int port, fd, listener;
    pid_t pid;
    if ((listener  = socket_create(port)) < 0) {
        handle_error("sock_create()");
    }
    port = atoi(argv[1]);
    
    while (1) {
        if ((fd = accept(listener, NULL, NULL)) < 0) {
            handle_error("accept()");
        }
        if ((pid = fork()) < 0) {
            handle_error("fork()");
        }
        if (pid == 0) {
            close(listener);
            recv_file(fd);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

