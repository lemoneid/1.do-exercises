/*************************************************************************
	> File Name: thread_pool.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 04 Aug 2020 04:22:05 PM CST
 ************************************************************************/

#include "head.h"

extern int epollfd;
extern struct User *users;
extern int maxfd;

void get_name(int fd) {
    struct ChatMsg msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = CHAT_SYS;
    int cnt = 0;
    for (int i = 1; i <= maxfd; ++i) {
        if (cnt > 10) break;
        if (users[i].online == 1) {
            strcat(msg.msg, users[i].chat_name);
            strcat(msg.msg, ",");
            cnt++;
        }
    }
}

void send_all(struct ChatMsg *msg) {
    for (int i = 1; i <= maxfd; ++i) {
        if (users[i].online == 1) {
            send(users[i].fd, (void *)msg, sizeof(msg), 0);
        }
    }
}

void send_to(struct ChatMsg *msg) {
    char to_name[20] = {0};
    int i = 1; //@suyelu hello
    for (; i <= 21; ++i) {
        if (msg->msg[i] == ' ') break;
    }

} 

void do_work(struct User *user) {
    struct ChatMsg msg;
    char buff[512] = {0};
    if (recv(user->fd, &msg, sizeof(msg), 0) <= 0) {
        epoll_ctl(epollfd, EPOLL_CTL_DEL, user->fd, NULL);
        DBG(RED"<Reactor>"NONE" : Del from reactor!\n");
        close(user->fd);
        return ;
    } 
    user->flag = 10;
    if (msg.type & CHAT_PUB) {
        printf(BLUE"%s"NONE" ; %s\n", user->name, msg.msg);
        send_all(&msg);
    } else if (msg.type & CHAT_PRI) {
        printf(PINK"%s"NONE" : %s *\n", user->name, msg.msg);
        //send_to(&msg);
    } else if (msg.type & CHAT_FUNC) {
        if (msg.msg[0] != '#') {
            
        }
        
    } else if (msg.type & CHAT_SYN) {
        do_login(user, &msg);
    } else if (msg.type & CHAT_FIN) {
        msg.type = CHAT_FIN_1;
    }
}

void task_queue_init(struct task_queue *taskQueue, int size, int epollfd) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    taskQueue->users = calloc(size, sizeof(struct User));
    taskQueue->epollfd = epollfd;
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    return ;
}

void task_queue_push(struct task_queue *taskQueue, struct User *user) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        pthread_mutex_unlock(&taskQueue->mutex);
        DBG(YELLOW"<taskQueue>"NONE" : taskQueue is full!\n");
        return;
    }
    taskQueue->users[taskQueue->tail] = user;
    taskQueue->total++;
    DBG(GREEN"<Push>"NONE" : %s\n", user->name);
    if (++taskQueue->tail == taskQueue->size) {
        DBG(RED"<taskQueue>"NONE" : End\n");
        taskQueue->tail = 0;
    }
    //sleep(1);
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
}

struct User *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    //惊群效应
    while (taskQueue->total == 0) {
        DBG(PINK"<Debug>"NONE" : taskQueue is empty!\n ");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    struct User *user = taskQueue->users[taskQueue->head];
    taskQueue->total--;
    DBG(BLUE"<taskQueue>"NONE" : pop %d!\n", fd);
    if (++taskQueue->head == taskQueue->size) {
        taskQueue->head = 0;
    }
   // sleep(1);
    pthread_mutex_unlock(&taskQueue->mutex);
    return user;
}



void *thread_run(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        struct User *user = task_queue_pop(taskQueue);
        do_work(user);
    }
}

