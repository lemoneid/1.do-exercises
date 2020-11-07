/*************************************************************************
	> File Name: thread_pool.c
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Tue 04 Aug 2020 04:22:05 PM CST
 ************************************************************************/

#include "head.h"

extern int epollfd;
extern int repollfd, bepllfd;
extern struct User *bteam, *rteam;
extern struct BallStatus ball_status;
extern struct Bpoint ball;
extern struct Map court;

void send_all(struct FootBallMsg *msg) {
    for (int i = 1; i <= MAX; ++i) {
        if (bteam[i].online) send(bteam[i].fd, (void *)msg, sizeof(struct FootBallMsg), 0);
        if (rteam[i].online) send(rteam[i].fd, (void *)msg, sizeof(struct FootBallMsg), 0);
    }
}

void send_to(struct FootBallMsg *msg) {
    char to_name[20] = {0};
    int i = 1; //@suyelu hello
    for (; i <= 21; ++i) {
        if (msg->msg[i] == ' ') break;
    }

} 

void do_work(struct User *user) {
    struct FootBallMsg msg;
    bzero(&msg, sizeof(msg));
    char buff[512] = {0};
    //int size = recv(user->fd, (void *)*msg, sizeof(msg), 0);
    if (recv(user->fd, (void *)&msg, sizeof(msg), 0) <= 0) {
        epoll_ctl(epollfd, EPOLL_CTL_DEL, user->fd, NULL);
        DBG(RED"<Reactor>"NONE" : Del from reactor!\n");
        close(user->fd);
        return ;
    } 
    user->flag = 10;
    if (msg.type & FT_ACK) {
        if (user->team) {
            DBG(L_BLUE"%s"NONE " heart \n", user->name);        
        } else {
            DBG(L_RED"%s"NONE " heart \n", user->name);        
        }
    } else if (msg.type & (FT_WALL | FT_MSG)) {
        if (user->team) {
            DBG(L_BLUE"%s"NONE " %s\n", user->name, msg.msg);        
        } else {
            DBG(L_RED"%s"NONE " %s\n", user->name, msg.msg);        
        }
        strcpy(msg.name, user->name);
        msg.team = user->team;
        send_all(&msg);
    } else if (msg.type & FT_FIN) {
        DBG(RED"%d logout. \n", user->name);
        sprintf(buff, "%s Logout.", user->name);
        //加锁, 有线程并发问题，online为0，仍发消息
        user->online = 0;
        int epollfd_tmp = (user->team ? bepllfd : repollfd);
        del_event(epollfd_tmp, user->fd);
    
    } else if (msg.type & FT_CTL) {
        sprintf(buff, "Ctrl Message kick = %d", msg.ctl.strength);
        if (msg.ctl.action & ACTION_DFT) {
            user->loc.x += msg.ctl.dirx;
            user->loc.y += msg.ctl.diry;
            if (user->loc.x <= 1) user->loc.x = 1;
            if (user->loc.x >= court.width + 2) user->loc.x = court.width + 2;
            if (user->loc.y <= 0) user->loc.x = 0;
            if (user->loc.y >= court.height + 2) user->loc.y = court.height + 2;
        }
    } else if (msg.type & ACTION_KICK) {
        show_data_stream('k');
        sprintf(buff, "bx = %lf, by = %lf, px = %d, py = %d", ball.x, ball.y, user->loc.x, user->loc.y);
        Show_Message(, user, buff, 0);
        if (can_kick(&user->loc, msg.ctl.strength)) {
            ball_status.by_team = user->team;
            strcpy(ball_status.name, user->name);
            sprintf(buff, "vx = %d, vy = %f, ax = %f, ay = %f", ball_status.v.x, ball_status.v.y, ball_status.a.x, ball_status.a.y);
            Show_Message(, user, buff, 0);
        }

    } else if (msg.ctl.action & ACTION_STOP) {
        show_data_stream('s');
        if (can_access(&user->loc)) {
            bazero(&ball_status.v, sizeof(ball_status.v));
            bazero(&ball_status.a, sizeof(ball_status.a));
            sprintf(buff, "Stop the Ball");
            Show_Message(, user, buff, 0);
        }
    } else if (msg.ctl.action & ACTION_CARRY) {
        show_data_stream('c');
        sprintf(buff, "Try Carry the BAll");
        Show_Message(, user, buff, 0);
    }
}

void task_queue_init(struct task_queue *taskQueue, int size, int epollfd) {
    taskQueue->size = size;
    taskQueue->total = taskQueue->head = taskQueue->tail = 0;
    taskQueue->team = calloc(size, sizeof(struct User));
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
    taskQueue->team[taskQueue->tail] = user;
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
    struct User *user = taskQueue->team[taskQueue->head];
    taskQueue->total--;
    DBG(BLUE"<taskQueue>"NONE" : pop %s!\n", user->name);
    if (++taskQueue->head == taskQueue->size) {
    DBG(L_GREEN"<taskQueue>"NONE" : taskQueue End!\n");
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

