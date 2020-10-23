/*************************************************************************
	> File Name: client.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月21日 星期三 19时15分47秒
 ************************************************************************/

#include "head.h"
int server_port = 0;
char server_ip[20] = {0};
int team = -1;
char *conf = "./football.conf";
int sockfd = -1;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s id port\n", argv[0]);
        exit(1);
    }
    strcpy(server_ip, argv[1]);
    server_port = atoi(argv[2]);
    struct sockaddr_in server;
    socklen_t addr_len = sizeof(server);
    if ((sockfd = socket_udp()) < 0) {
        perror("udp");
        exit(1);
    }
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    //ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //注意网络序转换
    server.sin_port = htons(server_port);
    while (1) {
        char buff[512];
        scanf("%s", buff);
        struct User user;
        user.team = 0;
        strcpy(user.name, buff);
        user.online = 1;
        user.loc.x = 20;
        user.loc.y = 20;
        user.fd = sockfd;
        user.flag = 10;
        struct LogRequest request;
        strcpy(request.name, "yzw");
        request.team = 1;
        strcpy(request.msg, buff);

        if ((sendto(sockfd, &request, sizeof(struct LogRequest), 0, (struct sockaddr *)&server, sizeof(struct sockaddr))) > 0) {
            printf("success\n");
            memset(buff, 0, sizeof(buff));
            memset(&user, 0, sizeof(struct User));

            recvfrom(sockfd, &user, sizeof(struct User), 0, (struct sockaddr *)&server, &addr_len); 
            printf("server:--%d--%s\n",addr_len, user.name);
        }
    } 
    return 0;
}
