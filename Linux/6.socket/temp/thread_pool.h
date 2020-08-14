/*************************************************************************
	> File Name: thread_pool.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 16时16分57秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include "head.h"

#define MAX 10
#define MAXUSER 1024
#define BUFFSIZE 512
#define THREADNUM 5 

typedef struct Data {
    char *str;
    int fd;
} Data;

struct task_queue {
    int head;
    int tail;
    int size;
    int cnt;
    int epollfd;
    //struct Data *data;
    int *fd;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

int task_queue_push(struct task_queue *taskQueue, int fd);

struct task_queue *task_queue_init(struct task_queue *taskQueue, int size);
Data *task_queue_pop(struct task_queue *taskQueue);
void task_queue_clear(struct task_queue *taskQueue);
void *thread_run(void *arg);

#endif
