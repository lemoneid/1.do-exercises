/*************************************************************************
	> File Name: 1.fork.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月05日 星期一 11时08分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

char buff[] = "a write to stdout";
int global = 6;

int main() {
    pid_t pid;
    if (write(STDOUT_FILENO, buff, sizeof(buff)) != sizeof(buff)) {
        perror("write");
        exit(1);
    }
    int val = 99;
    printf("before fork\n");
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        global++;
        val++;
    }
    printf("pid = %lld, global = %d, var = %d\n", (long long)(getpid()), global, val);
    return 0;
}
