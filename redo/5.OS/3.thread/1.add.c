/*************************************************************************
	> File Name: 1.add.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 15时32分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

void *print(void *arg) {
    int tmp = *(int *)arg;
    printf("this is the %d thread\n", tmp);
}

int main() {
    int arr[105];
    pthread_t tid[100];
    for (int i = 1; i < 100; i++) {
        arr[i] = i;
        pthread_create(&tid[i], NULL, print, (void *)&arr[i]);
    }
    for (int i = 0; i < 100; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
