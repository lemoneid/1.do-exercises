/*************************************************************************
	> File Name: common.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月08日 星期六 14时31分11秒
 ************************************************************************/

// static extern

#include "head.h"
char conf_value_ans[512] = {0};

void get_info(const char *names, struct User *user, char *ip) {
    FILE *fp = NULL;
    char *line = NULL, *sub = NULL;
    ssize_t nread, len;
    if (names == NULL || user == NULL || ip == NULL) {
        errno = EINVAL;
        return ;
    }
    if ((fp = fopen(names, "r")) == NULL) {
        errno = EINVAL;
        return ;
    }

    strcpy(user->ip, ip);
    while ((nread = getline(&line, &len, fp)) != -1) {
        if ((sub = strstr(line, ip)) == NULL) {
            continue;;
        }
        int len0 = 0, len1 = 0, len2 = 0;
        
        while (line[len0] == ' ') len0++;
        len1 = len0;
        while (line[len1] != ' ') len1++;
        strncpy(user->id, line + len0, len1);
        while (line[len1] != ':') len1++;

        DBG(RED"<get_info>"NONE " len1 = %d, id = %s", len1,user->id);
        len2 = len1 + 1;
        while (line[len2] == ' ') len2++;
        len1 = len2;
        while (line[len2] != ' ') len2++;
        strncpy(user->name, line + len1, len2 - len1);
        DBG(RED"<get_info>"NONE " len2 = %d, name = %s", len2,user->name);
        while (line[len2] != ':') len2++;
        break;
    }
    if (sub == NULL) {
        strcpy(user->name, "Unkown");
    }
    free(line);
    fclose(fp);
    return ;
}

char *get_conf(const char *conf, char *key) {
    FILE *fp = NULL; 
    char *line = NULL, *sub = NULL;
    ssize_t nread, len;
    //optarg的实现，静态变量
    if (conf == NULL || key == NULL) {
        errno = EINVAL;
        return NULL;
    }
    if ((fp = fopen(conf, "r")) == NULL) {
        //perror("fopen()");
        errno = EINVAL;
        return NULL;
    }

    while ((nread = getline(&line, &len, fp)) != -1) {
        if ((sub = strstr(line, key)) == NULL) {
            continue;
        }
        if (line[strlen(key)] == '=') {
            strncpy(conf_value_ans, sub + strlen(key) + 1, nread - strlen(key) - 2);
            *(conf_value_ans + nread - strlen(key) - 2) = '\0';
            break;
        }
    }
    free(line);
    fclose(fp);
    //if (!strlen(conf_value_ans)) return NULL;
    if (sub == NULL) return NULL;
    return conf_value_ans;
}

int make_non_block(int fd) {
    int flag; 
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    //flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag|O_NONBLOCK);
    return 0;
}

int make_block(int fd) {
    int flag; 
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    fcntl(fd, F_SETFL, flag&~O_NONBLOCK);
    return 0;
}

int socket_create(int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    int val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0) {
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    if (listen(sockfd, 10) < 0) {
        return -1;
    }

    return sockfd;
}

int socket_connect(char *ip, int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
        
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    //server.sin_addr.s_addr = inet_addr("0.0.0.0");
    server.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }
    
    return sockfd;
}

