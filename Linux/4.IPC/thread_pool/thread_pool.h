/*************************************************************************
	> File Name: thread_pool.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 16时16分57秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "head.h"

struct task_queue {
    int head;
    int tail;
    int size;
    int cnt;
    char **data;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

struct task_queue * task_queue_init(struct task_queue *taskQueue, int size);

int task_queue_push(struct task_queue *taskQueue, char *str);
char *task_queue_pop(struct task_queue *taskQueue);
void task_queue_clear(struct task_queue *taskQueue);
void *thread_run(void *arg);

#endif
