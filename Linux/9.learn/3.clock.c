/*************************************************************************
	> File Name: 3.clock.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月05日 星期一 19时55分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#ifdef _D
#define DBG(frm, args...) printf(frm, ##args);
#else 
#define DBG(frm, args...)
#endif

int main() {
    int err;
    struct timespec tout;
    struct tm *tmp;
    char buff[512];
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&lock);
    DBG("the mutex is locked\n");
    clock_gettime(CLOCK_REALTIME, &tout);
    tmp = localtime(&tout.tv_sec);
    strftime(buff, sizeof(buff), "%r", tmp);
    tout.tv_sec += 10;

    return 0;
}
