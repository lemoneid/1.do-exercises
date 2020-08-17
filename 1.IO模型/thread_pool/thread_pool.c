/*************************************************************************
> File Name: thread_pool.c
> Author: suyelu 
> Mail: suyelu@126.com
> Created Time: Tue 04 Aug 2020 04:22:05 PM CST
************************************************************************/

#include "head.h"
#include "thread_pool.h"
#include "../chat.h"

extern int epollfd;
extern struct User user[MAXUSER];

int search_name(char *name) {
    for (int i = 0; i < MAXUSER; ++i) {
        if (user[i].online == 0) continue;
        if (strcmp(user[i].real_name, name) == 0) {
            return i;
        }
    }
    return -1;
}


void do_work(int fd) {
    struct ChatMsg cm;
    memset(&cm, 0, sizeof(cm));
    int nrecv;
    if ( (nrecv = recv(fd, &cm, sizeof(cm), 0)) <= 0) {
        if (epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL) < 0) {
            perror("epoll_ctl() ; del ");
        }
        DBG(RED"<Reactor>"NONE" : Del from reactor!\n");
        close(fd);
        return ;
    } 
    //make_non_block(i);
    if (cm.type & CHAT_ACK || nrecv > 0) {
        user[fd].flag = 10;
    }
    //make_block(i);
    printf(GREEN"<do_work>"NONE"type =%x, opt =%x, name =%s, msg =%s\n", cm.type, cm.opt, cm.name, cm.msg);
}

void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    taskQueue->fd = calloc(size, sizeof(int));
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    return ;
}

void task_queue_push(struct task_queue *taskQueue, int fd) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        pthread_mutex_unlock(&taskQueue->mutex);
        DBG(YELLOW"<taskQueue>"NONE" : taskQueue is full!\n");
        return;
    }
    taskQueue->fd[taskQueue->tail] = fd;
    taskQueue->total++;
    DBG(GREEN"<Push>"NONE" : %d\n", fd);
    if (++taskQueue->tail == taskQueue->size) {
        DBG(RED"<taskQueue>"NONE" : End\n");
        taskQueue->tail = 0;
    }
    //sleep(1);
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
}

int task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    //惊群效应
    while (taskQueue->total == 0) {
        DBG(PINK"<Debug>"NONE" : taskQueue is empty!\n ");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    int fd = taskQueue->fd[taskQueue->head];
    taskQueue->total--;
    DBG(BLUE"<taskQueue>"NONE" : pop %d!\n", fd);
    if (++taskQueue->head == taskQueue->size) {
        taskQueue->head = 0;
    }
    //sleep(1);
    pthread_mutex_unlock(&taskQueue->mutex);
    return fd;
}



void *thread_run(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        int fd = task_queue_pop(taskQueue);
        DBG(RED"<do_work-run>"NONE" ; fd = %d!\n",fd);
        do_work(fd);
    }
}

void *thread_heart(void *arg) {
    DBG(GREEN"<heart>"NONE" : is ready");
    while (1) {
        sleep(5);
        for (int i = 0; i < MAXUSER; ++i) {
       //     DBG(GREEN"<heart>"NONE" :test fd = %d is online\n", i);
            usleep(500);
            if (user[i].online == 0) continue;
            DBG(GREEN"<heart>"NONE" :test fd = %d, flag = %d\n", i, user[i].flag);
            if (user[i].flag == 0) {
                DBG(GREEN"<heart>"NONE": del fd = %d\n", i);
                //del
                user[i].online = 0;
                if (epoll_ctl(epollfd, EPOLL_CTL_DEL, i, NULL) < 0) {
                    perror("epoll_ctl() ; del ");
                }
                close(i);
            }  else if (user[i].flag > 0) {
                struct ChatMsg heart;
                heart.type |= CHAT_HEART;
                if (send(user[i].fd, &heart, sizeof(heart), 0) < 0) {
                    perror("send() : heart");
                }
                memset(&heart, 0, sizeof(heart));
                DBG(GREEN"<heart>"NONE" :send fd = %d\n", i);
                user[i].flag -= 1;
            }
        }

    }
}
