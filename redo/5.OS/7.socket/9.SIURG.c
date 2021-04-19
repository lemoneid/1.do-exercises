/*************************************************************************
	> File Name: 9.SIURG.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月13日 星期二 13时45分32秒
 ************************************************************************/

#include "head.h"

#define BUFFER_SIZE 1024

static int connfd;

void sig_urg(int sig) {
    int save_errno = errno;
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    int nrecv = recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
    printf("urg : get %d bytes content : %s\n", nrecv, buf);
    errno = save_errno;
    return ;
}

void add_sig(int sig, void(*sig_handler)(int)) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sig_handler;
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);
    assert(sigaction(sig, &sa, NULL) != -1);
    return ;
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        exit(1);
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
    }
    struct sockaddr_in client_address;
    socklen_t client_addrlength = sizeof(client_address);
    int connfd =  accept(sockfd, (struct sockaddr *)&client_address, &client_addrlength);
    if (connfd < 0) {
        perror("accept");
    } else {
        add_sig(SIGURG, sig_urg);
        fcntl(connfd, F_SETOWN, getpid());
        char buffer[BUFFER_SIZE];
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int nrecv = recv(connfd, buffer, BUFFER_SIZE - 1, 0);
            if (nrecv <= 0) break;
            printf("main : get %d bytes content : %s\n", nrecv, buffer);
        }
        close(connfd);
    }
    close(sockfd);

    return 0;
}
