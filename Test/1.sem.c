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

#define MAX_P 8 //最大进程数
#define MAX_N 3 //最大可用资源数
#define TOTAL 3 //data = 循环次数
#define P sem_wait
#define V sem_post 

sem_t *empty = NULL;
int data[MAX_P + 5];

void iswaiting(int x) {
    int t = rand() % 100;
    int cnt = 1;
    while (t & 1) {
        DBG(RED"序号:%d -- 第 %d 次等待\n"NONE, x, cnt++);
        t = rand() % 100;
        sleep(1);
    }
}

void out(int x) {
    while (1) {
        srand(time(0));
        if (data[x] < 1) return ;
        P(empty);
        //DBG(RED"%d 还有资源数 : %ld\n", x, empty->__align);
        iswaiting(x);
        printf(GREEN"序号:%d -- 第 %d 次离开\n"NONE, x, TOTAL - data[x] + 1);
        sleep(2);
        iswaiting(x);
        printf(PINK"序号:%d -- 第 %d 次返回\n"NONE, x, TOTAL - data[x] + 1);
        data[x]--;
        V(empty);
    }
}

int main() {
    pid_t pid;
    int shmid;
    sem_t *share_memory = NULL;
    key_t key = ftok(".", 2009);
    //创建共享内存--共享信号量
    if ((shmid =shmget(key, sizeof(sem_t), IPC_CREAT | 0666)) < 0) {
        handle_error("shmget()");
    }

    if ((share_memory = (sem_t *)shmat(shmid, NULL, 0)) == NULL) {
        handle_error("shmat()");
    }
    memset(share_memory, 0, sizeof(sem_t));
    empty = share_memory;
    sem_init(empty, 1, MAX_N);
    //多进程
    int x = 0;
    for (int i = 0; i < MAX_P; ++i) {
        data[i] = TOTAL;
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
        out(x);
    } else {
        for (int i = 0; i < MAX_P; ++i) {
            wait(NULL);
        }
    }
    sem_destroy(empty);
    return 0;
}

