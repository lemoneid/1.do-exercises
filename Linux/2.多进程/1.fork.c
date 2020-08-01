/*************************************************************************
	> File Name: 1.fork.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月30日 星期四 20时15分30秒
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    printf("%d\n", pid); 
    if (pid == 0) {
        pid_t pid1;
        if ((pid1 =fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid1 == 0) {
            printf("child child Process\n");
        }
        printf("In child Process\n");
        //execlp("/bin/ls","ls", "/etc", ".", NULL);
        //不执行
        //execlp("/bin/ls","ls", "/tmp", ".", NULL);
    } else {
        printf("In parent Process\n");
    }

    return 0;
}
