/*************************************************************************
	> File Name: sub_reactor.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月21日 星期三 20时29分57秒
 ************************************************************************/

#include "head.h"

void *sub_reactor(void *arg){
    //NTHREAD 线程数量小于cpu核心
    struct task_queue *taskQueue = (struct task_queue *)arg;
    pthread_t *tid = (pthread_t *)calloc(NTHREAD, sizeof(pthread_t));
    for (int i = 0; i < NTHREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue);
    }
7
    struct epoll_event ev, events[MAX];
    sigset_t mask, orig_mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    while (1) {
        DBG(LRED"Sub Reactor"NONE" ; Epoll Waiting...\n");
        pthread_sigmask(SIG_SETMASK, &mask, &orig_mask);
        int nfds = epoll_wait(task_queue->epollfd, events, MAX, -1);
        pthread_sigmask(SIG_SETMASK, &orig_mask, NULL);
        if (nfds < 0) {
            perror("main : epoll_wait()");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            struct User *user = (struct User *)events[i].data.ptr;
            bzero(&user, sizeof(user));
            if (events[i].data.fd == listener) {
                int new_fd = udp_accept(listener, &user);
                if (new_fd > 0) {
                    sprintf(buff, "%s login the Game.", user.name);
                    //Show_Message( , , buff, 1);
                    show_data_stream('l');
                    add_to_sub_reactor(&user);
                }
            }
        }

    }
8
    //死循环
        //epoll_wait
        //将返回的事件所关联到的user，push到相应的任务队列中
    return NULL;
}
