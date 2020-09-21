/*************************************************************************
	> File Name: ../common/file_transfer.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 20 Sep 2020 06:39:04 PM CST
 ************************************************************************/

#include "head.h"

void send_file(const char *filename, int sockfd) {
    FILE *fp = NULL;
    char *p = NULL;
    size_t size;
    struct FileMsg filemsg;
    if ((fp = fopen(filename, "rb")) == NULL) {
        perror("fopen()");
        return ;
    }
    memset(&filemsg, 0, sizeof(filemsg));
    fseek(fp, 0L, SEEK_END);
    filemsg.size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    strcpy(filemsg.filename, (p = strrchr(filename, '/')) ? p + 1 : filename);
    printf("size = %lld\n", filemsg.size);
    while (size = fread(filemsg.buff, 1, sizeof(filemsg.buff), fp)) {
        send(sockfd, (void *)&filemsg, sizeof(filemsg), 0);
        memset(filemsg.buff, 0, sizeof(filemsg.buff));
    }
    return ; 
}

void recv_file(int sockfd) {
    struct FileMsg packet, packet_t, packet_pre;
    int packet_size = sizeof(struct FileMsg);
    int offset = 0, cnt = 0;
    FILE *fp = NULL;
    size_t recv_size, write_size = 0, total_size = 0;
    bzero(&packet, 0);
    bzero(&packet_t, 0);
    bzero(&packet_pre, 0);
    while (1) {
        if (offset > 0) {
            memcpy(&packet, &packet_pre, offset);
        }
        while ((recv_size = recv(sockfd, (void *)&packet_t, packet_size, 0)) > 0) {
            if (offset + recv_size == packet_size) {
                memcpy((char *)&packet + offset, &packet_t, recv_size);
                offset = 0;
                printf(L_GREEN"整包\n"NONE);
                break;
            } else if (offset + recv_size < packet_size) {
                memcpy((char *)&packet + offset, &packet_t, recv_size);
                offset += recv_size; 
                printf(L_RED"拆包\n"NONE);
            } else {
                int need = packet_size - offset;
                memcpy((char *)&packet + offset, &packet_t, need);
                offset = recv_size - need;
                memcpy((char *)&packet_pre, (char *)&packet_t + need, offset);
                printf(YELLOW"粘包\n"NONE);
                break;
            }
        }
        if (!cnt) {
            printf("Start recv file %s, with size %lld!\n", packet.filename, packet.size);
            char name[1024] = {0};
            sprintf(name, "./data/%s", packet.filename);
            if ((fp = fopen(name, "wb")) == NULL) {
                perror("fopen()");
                return ;
            }
        }
        cnt++;
        if (packet.size - total_size >= sizeof(packet.buff)) {
            write_size = fwrite(packet.buff, 1, sizeof(packet.buff), fp);
        } else {
            write_size = fwrite(packet.buff, 1, packet.size - total_size, fp);
        }
        total_size += write_size;
        if (total_size >= packet.size) {
            printf("Finished!\n");
            break;
        }
    }
    fclose(fp);
    return ;
}

