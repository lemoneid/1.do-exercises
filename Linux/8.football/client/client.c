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
    DBG(GREEN"get_cjson\n"NONE);
    cJSON *cJSONFile = get_cjson(conf);
    struct LogRequest curHost;
    strcpy(curHost.name, get_cjson_valuestring("NAME"));
    curHost.team = team = get_cjson_valueint("TEAM");
    strcpy(curHost.msg, get_cjson_valuestring("LOGMSG"));

    strcpy(server_ip, get_cjson_valuestring("SERVERIP"));
    server_port = get_cjson_valueint("SERVERPORT");
    DBG(GREEN"IP = %s, port = %d"NONE, server_ip, server_port);

    struct sockaddr_in server;
    socklen_t addr_len = sizeof(server);
    if ((sockfd = socket_udp()) < 0) {
        perror("socket_udp");
        exit(1);
    }
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(server_port);

    while (1) {
        char buff[512];
        scanf("%s", buff);
        struct User user;
        if ((sendto(sockfd, &curHost, sizeof(struct LogRequest), 0, (struct sockaddr *)&server, sizeof(struct sockaddr))) > 0) {
            printf("success\n");
            memset(buff, 0, sizeof(buff));
            recvfrom(sockfd, &user, sizeof(struct User), 0, (struct sockaddr *)&server, &addr_len); 
            printf("server:--%d--%s\n",addr_len, user.name);
        }
    } 
    return 0;
}
