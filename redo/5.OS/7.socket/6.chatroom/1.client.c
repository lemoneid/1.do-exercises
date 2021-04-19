/*************************************************************************
	> File Name: 1.client.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 20时00分18秒
 ************************************************************************/
 #define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/poll.h>
#define BUFFER_SIZE 64

int main(int argc, char *argv[]) {
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        close(sockfd);
        exit(1);
    }

    struct pollfd fds[2];
    fds[0].fd = 0;
    fds[0].events = POLLIN;
    fds[0].revents = 0;
    fds[1].fd = sockfd;
    fds[1].events = POLLIN;
    fds[1].revents = 0;
    char buf[BUFFER_SIZE];
    int pipefd[2];
    int ret = pipe(pipefd);
    assert(ret != -1);
    while (1) {
        ret = poll(fds, 2, -1);
        if (ret < 0) {
            printf("poll failed\n");
            close(sockfd);
            break;
        }
        if (fds[1].revents & POLLIN) {
            memset(buf, 0, sizeof(BUFFER_SIZE));
            int nrecv = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
            if (nrecv < 0) {
                perror("recv");
                break;
            }
            if (nrecv == 0) {
                printf("the connection closed\n");
                break;
            }
            printf("%s\n", buf);
        }
        if (fds[0].revents & POLLIN) {
            ret = splice(0, NULL, pipefd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
            ret = splice(pipefd[0], NULL, sockfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
        }
    }
    close(sockfd);
    return 0;
}
