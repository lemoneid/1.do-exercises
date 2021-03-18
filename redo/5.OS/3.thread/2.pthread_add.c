/*************************************************************************
	> File Name: 2.pthread_add.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月18日 星期四 15时01分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#define INS 5

int now, sum;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now > 100) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        now++;
        sum += now;
        printf("<%ld> now = %d, sum = %d\n", pthread_self() ,now, sum);
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char **argv) {
    pthread_t tid[INS];
    for (int i = 0; i < INS; i++) {
        pthread_create(&tid[i], NULL, add, NULL);
    }
    for (int i = 0; i < INS; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("%d\n", sum);
    return 0;
}

