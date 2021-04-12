/*************************************************************************
	> File Name: 2.select.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月11日 星期日 20时50分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <sys/select.h>
#define handle_error(msg)\
    do { perror(msg), exit(EXIT_FAILURE); } while (0);

int main(int argc, char **argv) {
    if (argc <= 2) {
        fprintf(stderr, "usage : %s ip port\n", argv[0]);
        exit(0);
    }
    const char *ip = argv[1]; 
    int port = atoi(argv[2]);

    int listenfd;
    int connfd;
    struct sockaddr_in address;
    bzero(&address, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr("0.0.0.0");

    int val = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
        handle_error("setsockopt");
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("socket"); 
    }

    if (bind(listenfd, (struct sockaddr *)&address, sizeof(struct sockaddr_in)) < 0) {
        handle_error("bind");
    }
    
    if (listen(listenfd, 5) < 0) {
        handle_error("listen");
    }

    struct sockaddr_in client_address;
    socklen_t client_addrlength = sizeof(struct sockaddr_in);
    bzero(&client_address, sizeof(client_address));
    
    if ((connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength)) < 0) {
        close(listenfd);
        handle_error("accept");
    }
    
    char buf[1024];
    fd_set read_fds;
    fd_set exception_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&exception_fds);

    int ret;
    while (1) {
        memset(buf, sizeof(buf), 0);
        FD_SET(connfd, &read_fds);
        FD_SET(connfd, &exception_fds);
        ret = select(connfd + 1, &read_fds, NULL, &exception_fds, NULL);
        if (ret < 0) {
            perror("select");
            break;
        }
        if (FD_ISSET(connfd, &read_fds)) {
            ret = recv(connfd, buf, sizeof(buf) - 1, 0);
            if (ret <= 0) break;
            printf("get %d bytes of normal data : %s\n", ret, buf);
        } else if (FD_ISSET(connfd, &exception_fds)) {
            ret = recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
            if (ret <= 0) break;
            printf("get %d bytes of oob data : %s\n", ret, buf);
        }
    }
    close(connfd);
    close(listenfd);
    return 0;
}
