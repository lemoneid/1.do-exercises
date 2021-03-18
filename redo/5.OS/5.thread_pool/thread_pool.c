/*************************************************************************
	> File Name: thread_pool.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月18日 星期四 15时22分48秒
 ************************************************************************/

#include "thread_pool.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    taskQueue->data = calloc(sizeof(void *), size);
    pthread_mutex_init(taskQueue->mutex, NULL);
    pthread_cond_init(taskQueue->cond, NULL);
    return ;
}


void task_queue_push(struct task_queue *taskQueue, char *str) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->head) {
        pthread_mutex_unlock(&taskQueue->mutex);
        printf("<Debug>" " : taskQueue is full!\n");
        return ;
    }
    taskQueue->data[taskQueue->tail++] = strdup(str);
    taskQueue->total++;
    if (taskQueue->tail == taskQueue->total) {
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
    return ;
}

char *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    //惊群效应
    if (taskQueue->tail == taskQueue->head) {
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
}
