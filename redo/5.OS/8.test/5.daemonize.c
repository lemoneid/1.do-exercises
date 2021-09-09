/*************************************************************************
	> File Name: 5.daemonize.c
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月09日 星期四 12时42分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

bool dameonize() {
    pid_t pid = fork():
    if (pid < 0) {
        return false;
    } else if (pid > 0) {
        exit(0);
    }
    unmask(0);
    pid_t sid = setsid();
    if (sid < 0) {
        return false;
    }
    if ((chdir("/")) < 0) {
        return false;
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(sTDERR_FILENO);

    open("/dev/null", O_EDONLY);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_ERWR);
    return true;
}

int main() {



    return 0;
}
