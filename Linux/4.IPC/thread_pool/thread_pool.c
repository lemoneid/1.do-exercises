/*************************************************************************
	> File Name: thread_pool.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 16时22分10秒
 ************************************************************************/

#include "thread_pool.h" 
#include "head.h"

struct task_queue * task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue = (struct task_queue *)malloc(sizeof(struct task_queue));
    taskQueue->data = (char **)malloc(sizeof(char *) * size);
    taskQueue->head = taskQueue->tail = 0;
    taskQueue->cnt = 0;
    taskQueue->size = size;
    DBG(BLUE"<init>"NONE "head = %d, tail = %d, cnt = %d, size = %d\n", taskQueue->head, taskQueue->tail ,taskQueue->cnt, taskQueue->size);

    if (pthread_mutex_init(&(taskQueue->mutex), NULL) != 0) {
        printf("mutex init error");
        return NULL;
    }
    if (pthread_cond_init(&(taskQueue->cond), NULL) != 0) {
        printf("cond init error");
        return NULL;
    }
    return taskQueue;
}

int task_queue_push(struct task_queue *taskQueue, char *str) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue == NULL)  {
        DBG(BLUE"<PUSH>"NONE " NULL");
        pthread_mutex_unlock(&taskQueue->mutex);
        return -1;
    }
    if (taskQueue->cnt > taskQueue->size) {
        DBG(BLUE"<PUSH>"NONE " cnt = %d, size = %d\n", taskQueue->cnt, taskQueue->size);
        pthread_mutex_unlock(&taskQueue->mutex);
        return 0;
    } 
    //DBG(BLUE"<PUSH>"NONE " %s\n", str);
    (taskQueue->data)[taskQueue->tail] = strdup(str);
    taskQueue->tail++;
    DBG(BLUE"<PUSH>"NONE "%s\n", taskQueue->data[taskQueue->tail - 1]);
    if (taskQueue->tail == taskQueue->size) taskQueue->tail -= taskQueue->size;
    taskQueue->cnt += 1;

    //pthread_cond_broadcast(&(taskQueue->cond));
    pthread_mutex_unlock(&taskQueue->mutex);
    pthread_cond_signal(&(taskQueue->cond));
    return 1;
}

char *task_queue_pop(struct task_queue *taskQueue) {
    //pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue == NULL || taskQueue->cnt == 0) {
        pthread_mutex_unlock(&taskQueue->mutex);
        return NULL;
    }
    int idx = taskQueue->head++;
    DBG(BLUE"<POP>"NONE "%s\n", taskQueue->data[taskQueue->head - 1]);
    if (taskQueue->head == taskQueue->size) taskQueue->head -= taskQueue->size;
    taskQueue->cnt -= 1;
    //pthread_cond_broadcast(&(taskQueue->cond);
    //pthread_mutex_unlock(&taskQueue->mutex);
    return taskQueue->data[idx];
}

void task_queue_clear(struct task_queue *taskQueue) {
    
    if (taskQueue == NULL) return ;
    free(taskQueue->data);
    free(taskQueue);
    return ;
}

void *thread_run(void *arg) {
    printf("thread_run ready\n");
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        pthread_mutex_lock(&taskQueue->mutex);
        if (taskQueue->cnt == 0)  {
            printf(YELLOW"thread <%ld> "NONE" waiting\n", pthread_self());
            pthread_cond_wait(&(taskQueue->cond), &(taskQueue->mutex));
            //pause();
        }
        DBG(BLUE"<run>"NONE"thread_run_lock\n");
        char *str = task_queue_pop(taskQueue);
        printf(RED"<%ld>"NONE"%s\n", pthread_self(), str);
        pthread_mutex_unlock(&taskQueue->mutex);
        //sleep(1);
    }
}
