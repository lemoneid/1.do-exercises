/*************************************************************************
	> File Name: 1.pipe.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 11时47分33秒
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int pipefd[2];
    char buffer[1024];
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    
    if (pid == 0) {
        close(pipefd[0]);
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            scanf("%s", buffer);
            write(pipefd[1], buffer, strlen(buffer));
        }
    } else {
        close(pipefd[1]);
        while (1) {
            read(pipefd[0], buffer, sizeof(buffer));
            printf("%s\n", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }

    return 0;
}
