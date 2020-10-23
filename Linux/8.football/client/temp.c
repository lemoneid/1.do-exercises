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

int main(int argc, char **argv) {
    int opt;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));
    bzero(&response, sizeof(response));
    while ((opt = getopt(argc, argv, "h:p:t:m:n:")) != -1) {
        switch (opt) {
                //获取启动参数
                //h -> host
                //p -> port
                //m -> msg
                //t -> team
                //n -> name
            default:
                fprintf(stderr, "Usage : %s [-hptmn]!\n", argv[0]);
                exit(1);
        }
    }
    //请判断如果启动参数中没有这些配置，从配置文件中读取
    //请打印出上面的各配置信息，用以确定是否正确
    // main(int argc, char **argv) {
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
    return 0;
}
