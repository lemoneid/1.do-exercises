/*************************************************************************
	> File Name: sub_reactor.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月21日 星期三 20时29分57秒
 ************************************************************************/

#include "head.h"

void *sub_reactor(void *arg){
    struct task_queue *taskQueue = (struct task_queue *)arg;
    pthread_t *tid = (pthread_t *)calloc(NTHREAD, sizeof(pthread_t));
    for (int i = 0; i < NTHREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue);
    }
7
    struct epoll_event ev, events[MAX];
8
    //死循环
        //epoll_wait
        //将返回的事件所关联到的user，push到相应的任务队列中
    return NULL;
}
