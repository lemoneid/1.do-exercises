/*************************************************************************
	> File Name: 2.multi_process.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 12时59分20秒
 ************************************************************************/

#include "head.h" 

int main(int argc, char **argv) {
    pid_t pid;
    int x = 0;
    for (int i = 0; i < 100; ++i) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    } 
    if (pid == 0) {
        DBG(GREEN"<Debug>"NONE "我是第 %d 个孩子\n", x);
    } else {
        for (int i = 0; i < x; ++i) {
            wait(NULL);
        }
    }

    return 0;
}

