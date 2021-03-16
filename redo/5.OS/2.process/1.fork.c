/*************************************************************************
	> File Name: 1.fork.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 13时17分54秒
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid == 0) {
        printf("this is child\n");
        execl("/bin/ls", "ls", "/etc", ".", NULL);
        //子进程当前代码段为ls代码,内存空间完全替换,进程变为ls
    } else {
        printf("this is parent\n");
    }

    return 0;
}
