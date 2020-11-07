/*************************************************************************
	> File Name: temp.c
	> Author: wei 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri Oct 23 19:58:59 2020
 ************************************************************************/

#include "head.h"
int server_port = 0;
char server_ip[20] = {0};
int team = -1;
char *conf = "./football.conf";
int sockfd = -1;
char host[20] = {0};

int main(int argc, char **argv) {
    int opt;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));
    bzero(&response, sizeof(response));
    while ((opt = getopt(argc, argv, "h:p:t:m:n:")) != -1) {
        switch (opt) {
            case 'h' : strcpy(host, optarg); break;
            case 'p' : server_port = atoi(optarg); break;
            case 'm' : strcpy(request.msg, optarg); break;
            case 't' : request.team = atoi(optarg);  break;
            case 'n' : strcpy(request.name, optarg); break;
            default:
            fprintf(stderr, "Usage : %s [-hptmn]!\n", argv[0]);
            exit(1);
        }
    }
    //请判断如果启动参数中没有这些配置，从配置文件中读取
    DBG(GREEN"Name = %s, team = %d, msg = %s, IP = %s, port = %d\n"NONE,request.name, request.team, request.msg ,server_ip, server_port);
    DBG(GREEN"Checking config file...\n");
    if (request.name == NULL) strcpy(request.name, get_conf_value(conf, "NAME"));
    if (request.team == -1) request.team = team = atoi(get_conf_value(conf, "TEAM"));
    if (request.msg == NULL) strcpy(request.msg, get_conf_value(conf, "LOGMSG"));
    if (server_ip == NULL) strcpy(server_ip, get_conf_value(conf, "SERVERIP"));
    if (server_port == 0)server_port = atoi(get_conf_value(conf, "SERVERPORT"));
    DBG(GREEN"Name = %s, team = %d, msg = %s, IP = %s, port = %d"NONE,request.name, request.team, request.msg ,server_ip, server_port);

    DBG(GREEN"server init..."NONE);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip);
    socklen_t len = sizeof(server);
    if ((sockfd = socket_udp()) < 0) {
        perror("socket_udp()");
        exit(1);
    }
    sendto(sockfd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&server, len);
    //  在这里，请使用select做定时，如果超过时间没有收到数据，判定为server不在线
    //  retval就是select的返回值
    fd_set rdfds;
    struct timeval timeout;
    FD_ZERO(&rdfds);
    FD_SET(socketfd, &rdfds);
    timeout.tv_sec = 5;
	timeout.tv_usec = 0;
    int retval = select(sockfd + 1, &rdfds, NULL, NULL, &timeout);
    if (retval < 0) {
        perror("select");
        exit(1);
    } else if (retval){
        int ret = recvfrom(sockfd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&server, &len);
        if (ret != sizeof(response) || response.type) {
            printf("The Game Server refused your login.\n\tThis May be helpful:%s\n", response.msg);
            exit(1);
        }
    } else {
        printf("The Game Server is out of service!.\n");
        exit(1);
    }
    connect(sockfd, (struct sockaddr *)&server, len);
    
    struct ChatMsg msg;
    while (1) {
        memset(&msg, 0, sizeof(msg));
        msg.type = CHAT_WALL;
        scanf("%[^\n]s", msg.msg);
        getchar();
        strcpy(msg.name, request.name);
        if (strlen(msg.msg)) {
            
        }
    }

    return 0;
}
