/*************************************************************************
	> File Name: 1.sem.c
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 23 Sep 2020 09:48:54 PM CST
 ************************************************************************/

#include "head.h"
#include <semaphore.h>

#define handle_error(msg)\
    do{perror(msg);exit(EXIT_FAILURE);}while(0);

#define MAX_P 6 //最大进程数
#define MAX_N 3 //最大可用资源

#define P sem_wait
#define V sem_post 

sem_t full;
sem_t empty;
sem_t mutex;

int data[MAX_P + 5];

void out(int x) {
    while (1) {
        srand(time(0));
        P(&empty);
        P(&mutex);
        int t = rand() % 100;
        while (t & 1) {
            t = rand() % 100;
            sleep(1);
        }
        printf("%d 离开宿舍\n", x);
        V(&mutex);
        t = rand() % 100;
        while (t & 1) {
            t = rand() % 100;
            sleep(1);
        }
        printf("%d 回到宿舍\n", x);
        //V(&full);
        V(&empty);
    }
}

void back() {
    while (1) {

    }
}

int main() {
    pid_t pid;
    sem_init(&full, 1, 0);
    sem_init(&empty, 1, MAX_N);
    sem_init(&mutex, 1, 1);
    int x = 0;
    for (int i = 0; i < MAX_P; ++i) {
        data[i] = MAX_N;
    }
    for (int i = 0; i < MAX_P; ++i) {
        if ((pid = fork()) < 0) {
            handle_error("fork()");
        }
        x = i;
        if (pid == 0) break;
    }
    if (pid == 0) {
        //DBG("the %d child\n", x);
        for (int i = 0; i < 3; ++i)
        out(x);
    } else {
        for (int i = 0; i < MAX_P; ++i) {
            wait(NULL);
        }
    }
    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&mutex);
    return 0;
}

