/*************************************************************************
	> File Name: 4.time_wheel_timer.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月14日 星期三 20时40分23秒
 ************************************************************************/

#ifndef _TIME_WHEEL_TIMER_H
#define _TIME_WHEEL_TIMER_H

#include <netinet/in.h>
#include <stdio.h>
#define BUFFER_SIZE 64
class tw_timer;
class client_data {
    struct sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    tw_timer* timer;
};

class tw_timer {
public :
    tw_timer(int rot, int ts) : next(nullptr), prev(nullptr), rotation(rot), time_slot(ts) {}
public :
    int rotation; //转多少圈生效
    int time_slot; //对应槽
    void (*cb_func)(client_data *);
    client_data *user_data;
    tw_timer *prev, *next;
};

class time_wheel {
public :
    time_wheel();
    ~time_wheel();
    tw_timer* add_timer(int timeout);
    void del_timer(tw_timer *timer);
    void tick();
private :
    static const int N = 60; //槽总数
    static const int INTERVAL = 1; //一个槽代表的时间间隔
    tw_timer *slots[N];
    int cur_slot;
};

time_wheel::time_wheel() : cur_slot(0) {}
time_wheel::~time_wheel() {
    for (int i = 0; i < N; i++) {
        tw_timer *p = slots[i];
        while (p) {
            slots[i] = p->next;
            delete p;
            p = slots[i];
        }
    }
}
tw_timer *time_wheel::add_timer(int timeout) {
    if (timeout < 0)  return nullptr;
    int ticks = 0;
    ticks = timeout < INTERVAL ? 1 : timeout / INTERVAL;
    int rotation = ticks / N;
    int idx = (cur_slot + (ticks % N)) % N;
    tw_timer* timer = new tw_timer(rotation, idx);
    if (!slots[idx]) {
        printf("add timer, rotation is %d, idx is %d, cur_slot is %d\n", rotation, idx, cur_slot);
        slots[idx] = timer;
    } else {
        timer->next = slots[idx];
        slots[idx]->prev = timer;
        slots[idx] = timer;
    }
    return timer;
}
void time_wheel::del_timer(tw_timer *timer) {
    if (!timer)  return ;
    int idx = timer->time_slot;
    if (timer == slots[idx]) {
        slots[idx] = slots[idx]->next;
        if (slots[idx]) {
            slots[idx]->prev = NULL;
        }
        delete timer;
    } else {
        timer->prev->next = timer->next;
        if (timer->next) {
            timer->next->prev = timer->prev;
        }
        delete timer;
    }
}
//向前滚动一个槽的间隔 INTERVAL
void time_wheel::tick() {
    tw_timer *p = slots[cur_slot];
    printf("current slot is %d\n", cur_slot);
    while (p) {
        printf("tick the timer once\n");
        if (p->rotation > 0) {
            p->rotation--;
            p = p->next;
        } else {
            p->cb_func(p->user_data);
            if (p == slots[cur_slot]) {
                printf("delete header in cur_slot\n");
                slots[cur_slot] = p->next;
                delete p;
                if (slots[cur_slot]) {
                    slots[cur_slot]->prev = nullptr; 
                }
                p = slots[cur_slot];
            } else {
                p->prev->next = p->next;
                if (p->next) {
                    p->next->prev = p->prev;
                }
                tw_timer *q = p->next;
                delete p;
                p = q;
            }
        }
        cur_slot = (++cur_slot) % N;
    }
}
#endif
