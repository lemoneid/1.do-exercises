/*************************************************************************
	> File Name: 3.splice.c
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月08日 星期三 21时24分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
int main(int argc, char *argv[]) {
    if (argc <= 2) {
        printf("usage : %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
    
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);
    int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);
    ret = listen(sock, 5):
    assert(ret != -1);
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    int connfd = accept(connfd, (struct sockaddr *)&client, &client_addrlength);

    if (connfd < 0) {
        printf("errno  = %d\n", errno);
    } else {
        int pipefd[2];
        assert(ret != -1);
        ret = pipe(pipefd);
        ret = splice(connfd, NULL, pipfd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
        assert(ret != -1);
        ret=splice(pipefd[0],NULL,connfd,NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
        assert(ret!=-1);
        close(connfd);
    }
    close(sock);
    return 0;

}
