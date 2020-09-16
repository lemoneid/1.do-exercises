/*************************************************************************
> File Name: thread_pool.c
> Author: weier 
> Mail: 1931248856@qq.com
> Created Time: 2020年08月04日 星期二 16时22分10秒
************************************************************************/

#include "thread_pool.h" 
#include "head.h"

struct task_queue *task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue = (struct task_queue *)malloc(sizeof(struct task_queue));
    taskQueue->data = (Data *)calloc(size, sizeof(Data));
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

int task_queue_push(struct task_queue *taskQueue, int fd) {
    pthread_mutex_lock(&taskQueue->mutex);
    char buff[BUFFSIZE] = {0};
    int nrecv = recv(fd, buff, sizeof(buff), 0);
    if (nrecv <= 0) {
        printf(RED"<fd = %d>"NONE" is logout\n", fd);
        if (epoll_ctl(taskQueue->epollfd, EPOLL_CTL_DEL, fd, NULL) < 0) {
            perror("epoll_ctl(): del");
            exit(1);
        }
        close(fd);
        pthread_mutex_unlock(&taskQueue->mutex);
    } else {
        if (taskQueue == NULL)  {
            DBG(BLUE"<PUSH>"NONE " : NULL");
            pthread_mutex_unlock(&taskQueue->mutex);
            return -1;
        }
        if (taskQueue->cnt >= taskQueue->size) {
            DBG(BLUE"<PUSH Full>"NONE " : cnt = %d, size = %d\n", taskQueue->cnt, taskQueue->size);
            pthread_mutex_unlock(&taskQueue->mutex);
            return 0;
        } 
        DBG(BLUE"<PUSH-1>"NONE " str = %s; strlen = %ld\n", buff, strlen(buff));
        DBG(BLUE"<PUSH-2>"NONE " fd = %d\n",  fd);
        taskQueue->data[taskQueue->tail].str = strdup(buff);
        taskQueue->data[taskQueue->tail].fd = fd;
        taskQueue->tail++;
        if (taskQueue->tail == taskQueue->size) taskQueue->tail = 0;
        taskQueue->cnt += 1;
        pthread_cond_signal(&(taskQueue->cond));
        DBG(BLUE"<PUSH>"NONE " Finish!\n");
        pthread_mutex_unlock(&taskQueue->mutex);
    }
    return 1;

}

Data *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue == NULL) {
        pthread_mutex_unlock(&taskQueue->mutex);
        return NULL;
    }

    DBG(BLUE"<POP>"NONE "in pop!");
    //惊群效应
    while (taskQueue->cnt == 0) {
        DBG(YELLOW"thread <%ld> "NONE" waiting\n", pthread_self());
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    int id = taskQueue->head;

//    data->str = taskQueue->data[taskQueue->head].str;
  //  data->fd = taskQueue->data[taskQueue->head].fd;
    taskQueue->head++;
    taskQueue->cnt -= 1;
    DBG(BLUE"<POP>"NONE "%s cnt = %d\n", taskQueue->data[id].str, taskQueue->cnt);
    if (taskQueue->head == taskQueue->size) taskQueue->head = 0;
    //pthread_cond_broadcast(&(taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
    return &taskQueue->data[id];
}

void task_queue_clear(struct task_queue *taskQueue) {

    if (taskQueue == NULL) return ;
    free(taskQueue->data);
    free(taskQueue);
    return ;
}
void *thread_run(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        Data *data = task_queue_pop(taskQueue);
        printf(RED"<%ld>"NONE PINK"<%d>" " : %s", pthread_self(), data->fd, data->str);
        free(data->str);
        //sleep(1);
    }
}

