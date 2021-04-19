/*************************************************************************
	> File Name: unblock_connect.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 19时26分19秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024


int set_nonblock(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = O_NONBLOCK | old_option;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

int set_block(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = (~O_NONBLOCK) & old_option;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

int unblock_connect(const char *ip, int port, int time) {
    int ret = 0;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);
    
    int sockfd, val = 1;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    set_nonblock(sockfd);
    ret = connect(sockfd, (struct sockaddr *)&address, sizeof(struct sockaddr_in));
    
    printf("the ret = %d\n", ret);
    if (ret == 0) {
        printf("connect with server immediately\n");
        set_block(sockfd);
        return sockfd;
    }
    if (errno != EINPROGRESS) {
        printf("unblock_connect not support\n");
        return -1;
    }

    //fd_set readfds;
    fd_set writefds;
    struct timeval timeout;

    FD_ZERO(&writefds);
    FD_SET(sockfd, &writefds);

    timeout.tv_sec = time;
    timeout.tv_usec = 0;

    ret = select(sockfd + 1, NULL, &writefds, NULL, &timeout);
    if (ret <= 0) {
        printf("connect time out");
        close(sockfd);
        return -1;
    }
    if (!FD_ISSET(sockfd, &writefds)) {
        printf("no events on sockfd found\n");
        close(sockfd);
        return -1;
    }

    int error = 0;
    socklen_t length = sizeof(error);

    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &length) < 0) {
        perror("getsockopt");
        close(sockfd);
        return -1;
    }
    if (error != 0) {
        printf("connect failed after select with the error : %d\n", error);
        close(sockfd);
        return -1;
    }
    printf("connect success! sockfd : %d\n", sockfd);
    set_block(sockfd);
    return sockfd;
}




int main(int argc, char *argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd = unblock_connect(ip, port, 10);
    if (sockfd < 0) {
        perror("unblock_connect");
        exit(1);
    }
    return 0;
}
