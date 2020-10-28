/*************************************************************************
	> File Name: thread_pool.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 04 Aug 2020 04:16:34 PM CST
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

struct task_queue{
    int size;
    int total;
    int head;
    int tail;
    int *fd;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};
int search_name(char *name); 
void task_queue_init(struct task_queue *taskQueue, int size);
void task_queue_push(struct task_queue *taskQueue, int fd);
int task_queue_pop(struct task_queue *taskQueue);
void *thread_run(void *arg);
void *thread_heart(void *arg);
void init_anon();
#endif
