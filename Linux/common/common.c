/*************************************************************************
	> File Name: common.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月08日 星期六 14时31分11秒
 ************************************************************************/

// static extern

#include "head.h"
char conf_value_ans[512] = {0};

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

