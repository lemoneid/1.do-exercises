/*************************************************************************
> File Name: server.c
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月09日 星期日 16时12分27秒
************************************************************************/

#include "head.h"
#include "./chat.h"

char ip[20] = {0}, name[20] = {0};
int sockfd, port;

void *do_recv() {
    struct ChatMsg cm;
    while (1) {
        memset(&cm, 0, sizeof(cm));
        int nrecv; 
        if (nrecv = recv(sockfd, &cm, sizeof(cm), 0) <= 0) {
            perror("recv() : heart");
            exit(1);
        }
        
        if (cm.type & CHAT_FIN_1) {
            printf("the client is exit!\n");
            exit(1);
        }
        if (cm.type & CHAT_FIN) {
            printf("the server is exit!\n");
            exit(1);
        }

        if (cm.type & CHAT_HEART) {
            cm.type |= CHAT_ACK;
            send(sockfd, &cm, sizeof(cm), 0);
        }
        if (cm.type & CHAT_PRI) {
            printf(RED"<PRI>"NONE BLUE"%s"NONE":%s\n", cm.name, cm.msg);
        } else if (cm.type & CHAT_PUB) {
            printf(YELLOW"<PUB>"NONE BLUE"%s"NONE":%s\n", cm.name, cm.msg);
        }
        if (cm.opt & FUNC_CHECK_ONLINE) {
            printf("the people online is %s!\n", cm.msg);
        }
        if (cm.opt & FUNC_CHANGE_NAME) {
            printf("you have changed your name success!\n");
            strcpy(name, cm.name);
        }

    }
}

void handle(char *buff, struct ChatMsg *cm) {
    int id = 0;
    while (buff[id] == ' ') id++;
    if (buff[id] == '#') {
        id++;
        char tmp[512] = {0};
        int cnt = sscanf(buff + id, "%s", tmp);
        id += cnt;
        if (strcmp(tmp, "1") == 0) {
            DBG(GREEN"<Degug>"NONE"FUNC_CHECK_ONLINE");
            cm->opt |= FUNC_CHECK_ONLINE; 
        } else if (strcmp(tmp, "2") == 0) {
            cm->opt |= FUNC_CHANGE_NAME;
            sscanf(buff + id, "%s", tmp);
            strcpy(cm->name, tmp);
            DBG(GREEN"<Degug>"NONE"FUNC_CHANGE_NAME name=%s\n", cm->name);
            
        } else {
            printf("the # arg is fault!\n");
        }
        return ;
    }
    
    if (buff[id] == '@') {
        id++;
        int s =id;
        cm->type |= CHAT_PRI;
        DBG(GREEN"<Degug>"NONE"CHAT_PRI");
        while (buff[id] != ' ') id++;
        strncpy(cm->name, buff + s, id - s);
        strcpy(cm->msg, buff + id);
        return ;
    } else {
        DBG(GREEN"<Degug>"NONE"CHAT_PUB");
        cm->type |= CHAT_PUB;
        strcpy(cm->msg, buff + id);
        return ;
    }
}

void *Stop(int signum) {
    struct ChatMsg cm;
    memset(&cm, 0, sizeof(cm));
    cm.type |= CHAT_FIN;
    printf("\n!!! you will logout\n");
    send(sockfd, &cm, sizeof(cm), 0);
}


int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    //conf
    get_conf("./info.conf", "SERVERIP");
    strcpy(ip, conf_value_ans);
    get_conf("./info.conf", "SERVERPORT");
    port = atoi(conf_value_ans);
    get_conf("./info.conf", "name");
    strcpy(name, conf_value_ans);
    //getopt
    int opt;
    // bug : -p 无参,接-n， 导致 p的optarg为(-n省)
    while ((opt = getopt(argc, argv, "h:p:n:"))  != -1) {
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

    DBG(GREEN"<arg>"NONE" : ip =%s, port =%d, name =%s\n", ip, port, name);

    //connect
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
    }
    struct timeval tv = {1, 0};
    socklen_t len = sizeof(tv);
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, len) < 0) {
        perror("setsockopt");
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        if (errno == EINPROGRESS) {
            fprintf( stderr, "time out\n");
            exit(1);
        }
        perror("connect");
        exit(0);
    }
    printf("connect success\n");

    // syn
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

    // recv -- thread
    pthread_t tid;
    pthread_create(&tid, NULL, do_recv, NULL);

    // ctrl + c

    signal(SIGINT, (void *)Stop);

    while (1) {
        struct ChatMsg cm;
        memset(&cm, 0, sizeof(cm));
        char buff[512] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        handle(buff, &cm);
        DBG(GREEN"<Degug>"NONE"type =%x, opt =%x, name =%s, msg =%s\n", cm.type, cm.opt, cm.name, cm.msg);
        send(sockfd, &cm, sizeof(cm), 0);
        //printf("Server : %s\n", buff);
    }

    return 0;
}
