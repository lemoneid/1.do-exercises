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
extern struct Anon anons[MAXUSER];

void init_anon() {
    int *fp = NULL, id = 0;
    char *line = NULL;
    ssize_t nread, len;
    if ((fp = fopen("./anon.conf", "r")) < 0) {
        perror("fopen()");
        return ;
    }
    while ((nread = getline(&line, &len, fd)) != -1) {
        if (id >= 100) break;
        strncpy(anons[id].name, line, sizeof(anons[id],name));
        anons[id].flag = 0;
        id++;
    }
    return ;
}

int search_anon() {
    int flag = 0;
    srand(time(0));
    while (!flag) {
        int op = rand  % 100;
        if (anons[op].flag == 0) return op;
    }
}

int search_name(char *name) {
    for (int i = 0; i < MAXUSER; ++i) {
        if (user[i].online != 1) continue;
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
            perror("epoll_ctl(); : do_work del ");
        }
        printf(RED"<Reactor>"NONE" : Del from reactor fd = %d!\n", fd);
        user[fd].online = 0;
        close(fd);
        return ;
    } 
   user[fd].flag = 10;
    
    //处理chatmsg
    if (cm.type & CHAT_FIN) {
        memset(&cm, 0, sizeof(cm));
        cm.type |= CHAT_FIN_1;
        printf(RED"\n<RECV>"NONE" : CHAT_FIN_1\n");
        send(fd, &cm, sizeof(cm), 0);
        return ;
    }

    if (cm.opt & FUNC_CHANGE_NAME) {
        DBG(RED"<RECV>"NONE" : FUNC_CHANGE_NAME %s\n", cm.name);
        int id = search_anon();
        strcpy (cm.name, anons[id].name);
        send(fd, &cm, sizeof(cm), 0);
        anons[id].flag = 1;
        user[fd].anon_idx = id;
       // strcpy (user[fd].real_name, cm.name);
    }

    if (cm.opt & FUNC_CHECK_ONLINE) {
        int cnt = 0;
        bzero(cm.msg, sizeof(cm.msg));
        for (int i = 0; i < MAXUSER; ++i) {
            if (user[i].online == 1) {
                cnt++;
                if (cnt > 10) continue; 
                strcat(cm.msg, user[i].real_name);
                strcat(cm.msg, "\n");
                DBG(RED"<name>"NONE" :  name = %s, msg =%s\n", user[i].real_name, cm.msg);
            }
        }
        char buff[50] = {0};
        sprintf(buff, "the total of people online is %d", cnt);
        strcat(cm.msg, buff);
        send(fd, &cm, sizeof(cm), 0);
    }

    if (cm.type & CHAT_PRI) {
        int id = search_name(cm.name);
        if (id >= 0) {
            strcpy(cm.name, user[fd].real_name);
            send(user[id].fd, &cm, sizeof(cm), 0);
        } else {
            cm.type = CHAT_SYS;
            send(fd, &cm, sizeof(cm), 0);
        }
    } else if (cm.type & CHAT_PUB) {
        strcpy(cm.name, user[fd].real_name);
        for (int i = 0; i < MAXUSER; ++i) {
            if (user[i].online == 1) {
                send(user[i].fd, &cm, sizeof(cm), 0);
            }
            //sleep(1);
        }
    }
    //printf(GREEN"<do_work>"NONE"type =%x, opt =%x, name =%s, msg =%s\n", cm.type, cm.opt, cm.name, cm.msg);
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

//心跳测试
void *thread_heart(void *arg) {
    DBG(GREEN"<heart>"NONE" : is ready");
    while (1) {
        sleep(5);
        for (int i = 0; i < MAXUSER; ++i) {
            usleep(500);
            if (user[i].online == 0) continue;
            DBG(GREEN"<heart>"NONE" :test fd = %d, flag = %d\n", i, user[i].flag);
            if (user[i].flag == 0) {
                DBG(GREEN"<heart>"NONE": del fd = %d\n", i);
                //del
                user[i].online = 0;
                if (epoll_ctl(epollfd, EPOLL_CTL_DEL, i, NULL) < 0) {
                    perror("epoll_ctl(); heart del ");
                }
                close(i);
            }  else if (user[i].flag > 0) {
                struct ChatMsg heart;
                heart.type |= CHAT_HEART;
                if (send(user[i].fd, &heart, sizeof(heart), 0) < 0) {
                    perror("send() : heart");
                    close(i);
                }
                memset(&heart, 0, sizeof(heart));
                user[i].flag -= 1;
            }
        }

    }
}
