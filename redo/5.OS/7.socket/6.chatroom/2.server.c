/*************************************************************************
	> File Name: 2.server.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 20时13分30秒
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
#define USER_LIMIT 5
#define FD_LIMIT 65536

struct client_data {
    struct sockaddr_in address;
    char *write_buf;
    char buf[BUFFER_SIZE];
};

void setnonblock(int fd) {
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return ;
}

int main(int argc, char *argv[]) {
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    int ret = 0, val = 1;
    ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    assert(ret != -1);
    ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);
    ret = listen(listenfd, 5);
    assert(ret != -1);


    struct client_data *users = calloc(FD_LIMIT, sizeof(struct client_data));
    int total = 0;
    struct pollfd fds[USER_LIMIT + 1];
    for (int i = 1; i <= USER_LIMIT; i++) {
        fds[i].fd = -1;
        fds[i].events = 0;
        fds[i].revents = 0;
    }
    fds[0].fd = listenfd;
    fds[0].events = POLLIN | POLLERR;
    fds[0].revents = 0;

    while (1) {
        ret = poll(fds, total + 1, -1);
        if (ret < 0) {
            printf("poll false\n");
            break;
        }
        for (int i = 0; i < total + 1; i++) {
            if ((fds[i].fd == listenfd) && (fds[i].revents & POLLIN)) {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(listenfd, (struct sockaddr *)&client_address, &client_addrlength);
                if (connfd < 0) {
                    perror("accept");
                    continue;
                }
                if (total >= USER_LIMIT) {
                    const char *info  = "too many users\n";
                    printf("%s", info);
                    send(connfd, info, strlen(info), 0);
                    close(connfd);
                    continue;
                }
                total++;
                users[connfd].address = client_address;
                setnonblock(connfd);
                fds[total].fd = connfd;
                fds[total].events = POLLIN | POLLERR;
                fds[total].revents = 0;
                printf("the new user : %d, total = %d\n", connfd, total);
            } else if (fds[i].revents & POLLERR) {
                printf("get an error from %d\n", fds[i].fd);
                char errors[100];
                memset(errors, 0, sizeof(errors));
                socklen_t length = sizeof(errors);
                if (getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, &errors, &length) < 0) {
                    printf("get socket option failed\n");
                }
                continue;
            } else if (fds[i].revents & POLLIN) {
                int connfd = fds[i].fd;
                memset(users[connfd].buf, 0, BUFFER_SIZE);
                int nrecv = recv(connfd, users[connfd].buf, BUFFER_SIZE - 1, 0);
                if (nrecv < 0) {
                    if (errno != EAGAIN) {
                        close(connfd);
                        users[fds[i].fd] = users[fds[total].fd];
                        fds[i] = fds[total];
                        i--;
                        total--;
                    }
                } else if (nrecv == 0) {
                    users[fds[i].fd] = users[fds[total].fd];
                    close(fds[i].fd);
                    fds[i] = fds[total];
                    i--;
                    total--;
                    printf("the client close\n");
                } else {
                    for (int j = 1; j <= total; j++) {
                        if (fds[j].fd == connfd) continue;
                        fds[j].events |= ~POLLIN;
                        fds[j].events = POLLOUT;
                        users[fds[j].fd].write_buf = users[connfd].buf;
                    }
                }
            } else if (fds[i].revents & POLLOUT) {
                int connfd = fds[i].fd;
                if (!users[connfd].write_buf) continue;
                ret = send(connfd, users[connfd].write_buf, strlen(users[connfd].buf), 0);
                users[connfd].write_buf = NULL;
                fds[i].events |= ~POLLOUT;
                fds[i].events |= POLLIN;
            }
        }

    }

    free(users);
    close(listenfd);
    return 0;
}

