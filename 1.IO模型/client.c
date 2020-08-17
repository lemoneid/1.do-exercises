/*************************************************************************
> File Name: server.c
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月09日 星期日 16时12分27秒
************************************************************************/

#include "head.h"
#include "./chat.h"

char ip[20] = {0}, name[20] = {0};

void handle(char *buff, struct ChatMsg *cm) {
    int id = 0;
    while (buff[id] == ' ') id++;
    while (buff[id] == '#') {
        id++;
        if (buff[id] == '1') {
            DBG(GREEN"<Degug>"NONE"FUNC_CHECK_ONLINE");
            cm->opt |= FUNC_CHECK_ONLINE; 
        }
        if (buff[id] == '2') {
            DBG(GREEN"<Degug>"NONE"FUNC_CHANGE_NAME");
            cm->opt |= FUNC_CHANGE_NAME;
            strcpy(cm->name, name);
            id++;
        }
    }
    if (buff[id] == '@') {
        id++;
        int s =id;
        cm->type |= CHAT_PRI;
        DBG(GREEN"<Degug>"NONE"CHAT_PRI");
        while (buff[id] != ' ') id++;
        strncpy(cm->name, buff + s, id - s);
        strcpy(cm->msg, buff + id);
    } else if (strlen(buff + id) > 0){
        DBG(GREEN"<Degug>"NONE"CHAT_PUB");
        cm->type |= CHAT_PUB;
        strcpy(cm->msg, buff + id);
    }
}


int main(int argc, char **argv) {
    int sockfd, port;
    if (argc  == 1){
        get_conf("./info.conf", "SERVERIP");
        strcpy(ip, conf_value_ans);
        get_conf("./info.conf", "SERVERPORT");
        port = atoi(conf_value_ans);
        get_conf("./info.conf", "name");
        strcpy(name, conf_value_ans);
    } else if (argc == 7){
        int opt;
        while ((opt = getopt(argc, argv, "h::p::n::"))  != -1) {
            switch(opt) {
                case 'h':
                    strcpy(ip, optarg);
                    break;
                case 'p':
                    port = atoi(optarg);
                    break;
                case 'n':
                    strcpy(name, optarg);
                    break;
                default:
                    fprintf(stderr, "Usage : %s ip port name!\n",argv[0]);
                    exit(1);
            }
        }
    } else {
        fprintf(stderr, "Usage : %s ip port name!\n",argv[0]);
        exit(1);
    }


    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect()");
        exit(1);
    }
    struct ChatMsg syn;
    syn.type |= CHAT_SYN;
    strcpy(syn.name, name);

    if (send(sockfd, &syn, sizeof(syn), 0) == -1) {
        perror("send()");
    }
    if (recv(sockfd, &syn, sizeof(syn), 0) == -1) {
        perror("recv");
    }
    if (syn.type & CHAT_NAK) {
        printf(" %s %s", syn.name,syn.msg);
        sleep(1);
        exit(1);
    } else if (syn.type & CHAT_ACK) {
        printf(" %s %s", syn.name,syn.msg);
    }

    while (1) {
        struct ChatMsg cm;
        memset(&cm, 0, sizeof(cm));
        char buff[512] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        handle(buff, &cm);
        DBG(GREEN"<Degug>"NONE"type =%x, opt =%x, name =%s, msg =%s\n", cm.type, cm.opt, cm.name, cm.msg);
        send(sockfd, &cm, sizeof(cm), 0);
        if (cm.type & CHAT_HEART) {
            cm.type |= CHAT_ACK;
            recv(sockfd, &cm, sizeof(cm), 0);
        }
        printf("Server : %s\n", buff);
    }

    return 0;
}
