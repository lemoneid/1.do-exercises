/*************************************************************************
	> File Name: 1.timer-list.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月13日 星期二 14时29分53秒
 ************************************************************************/

#ifndef LST_TIMER
#define LST_TIMER
#include <time.h>
#include <arpa/inet.h>
#include <stdio.h>
#define BUFFER_SIZE 64
class util_timer;

//用户数据结构
struct client_data {
    struct sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer *timer;
};

//定时器类
class util_timer {
public :
    util_timer() : prev(nullptr), next(nullptr) {}
    time_t expire;
    void (*cb_func)(client_data *);
    client_data *user_data;
    util_timer *prev, *next;
};

//定时器链表
class sort_timer_list {
public :
    sort_timer_list() : head(nullptr), tail(nullptr) {}
    ~sort_timer_list();
    void add_timer(util_timer *timer);
    void adjust_timer(util_timer *timer);
    void del_timer(util_timer *timer);
    void tick();
private : 
    void add_timer(util_timer *timer, util_timer *head);
    util_timer *head, *tail;
};

sort_timer_list::~sort_timer_list() {
    util_timer *p = head;
    while (p) {
        head = p->next;
        delete p;
        p = head;
    }
}
void sort_timer_list::add_timer(util_timer *timer) {
    if (!timer) return ;
    if (!head) {
        head = tail = timer;
        return ;
    }
    if (timer->expire < head->expire) {
        timer->next = head;
        head->prev = timer;
        head = timer;
        return ;
    }
    util_timer *p = head;
}

void sort_timer_list::adjust_timer(util_timer *timer) {
    if (!timer) return; 
    util_timer *q = timer->next;
    if (!q || timer->expire < q->expire) return ;
    if (timer == head) {
        head = head->next;
        head->prev = nullptr;
        timer->next = nullptr;
        add_timer(timer, head);
    } else {
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        add_timer(timer, timer->next);
    }
}

void sort_timer_list::del_timer(util_timer *timer) {
    if (!timer) return ;
    if (timer == head && timer == tail) {
        delete timer;
        head = nullptr;
        tail = nullptr;
        return ;
    }
    if (timer == head) {
        head = head->next;
        head->prev = nullptr;
        delete timer;
        return ;
    }
    if (timer == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete timer;
        return ;
    }
    timer->prev->next = timer->next;
    timer->next->prev = timer->prev;
    delete timer;
    return ;
}

void sort_timer_list::tick() {
    if (!head) return ;
    printf("timer tick\n");
    time_t cur = time(nullptr);
    util_timer *tmp = head;
    while (tmp) {
        if (cur < tmp->expire) break;
        tmp->cb_func(tmp->user_data);
        head = tmp->next;
        if (head) head->prev = nullptr;
        delete tmp;
        tmp = head;
    }
    return ;
}

void sort_timer_list::add_timer(util_timer *timer, util_timer *now) {
    util_timer* prev = now;
    util_timer* tmp = prev->next;
    while (tmp) {
        if (timer->expire < tmp->expire) {
            timer->next = tmp;
            timer->prev = prev;
            prev->next = timer;
            tmp->prev = timer;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp) {
        prev->next = timer;
        timer->prev = prev;
        timer->next = nullptr;
        tail = timer;
    }
}

#endif
