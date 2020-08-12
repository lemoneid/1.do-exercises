/*************************************************************************
	> File Name: 0.one_thread.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 12 Aug 2020 02:37:43 PM CST
 ************************************************************************/

#include "head.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }

    int server_listen, sockfd, port;
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }
    
    while (1) {
        struct sockaddr_in client;
        char buff[512] = {0};
        
        //useless
        struct User user;
        memset(&user, 0, sizeof(user));

        socklen_t len = sizeof(client);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept()");
            exit(1);
        }
        //useless
        get_info("../../common/names", &user, inet_ntoa(client.sin_addr));

        DBG("ip = %s, name = %s\n", inet_ntoa(client.sinaddr), user.name);
        read(sockfd, buff, sizeof(buff));
        printf(BLUE"%s"NONE" : %s\n", user.name, buff);
        close(sockfd);
    }

    return 0;

}
