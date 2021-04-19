/*************************************************************************
	> File Name: 5.heep_timer.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月14日 星期三 21时19分49秒
 ************************************************************************/

#ifndef _HEAP_TIMER
#define _HEAP_TIMER
#include <iostream>
#include <time.h>
#include <netinet/in.h>
using std::exception;
#define BUFFER_SIZE 64
class heap_timer;
class client_data {
    struct sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    heap_timer *timer;
};

class heap_timer {
public :
    heap_timer(int delay) {
        expire = time(NULL) + delay;
    }
public :
    time_t expire;
    void (*cb_func)(client_data *);
    client_data *user_data;
};

class time_heap {
public :    
    time_heap(int capacity) throw(std::exception);
    time_heap(heap_timer** init_array, int size, int capacity) throw(std::exception);
    ~time_heap();
    void add_timer(heap_timer *timer);
    void del_timer(heap_timer *timer);
    heap_timer *top() const;
    void pop_timer();
    void tick();
    bool empty() const;

private :
    void downUpdata(int ind);
    void resize();
    int capacity;
    int cur_size;
    heap_timer **array;

};

time_heap::time_heap(int capacity) throw(std::exception) : 
    capacity(capacity), cur_size(0) ,array(nullptr){
    array = new heap_timer*[capacity]{nullptr};
    if (!array) {
        throw(std::exception());
    }
}
time_heap::time_heap(heap_timer** init_array, int size, int capacity) throw(std::exception) :
    cur_size(size), capacity(capacity) {
    if (capacity < size) {
        throw(std::exception());
    }
    array = new heap_timer*[capacity]{nullptr};
    if (array) {
        throw std::exception();
    }
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            array[i] = init_array[i];
        }
        for (int i = (cur_size - 1) / 2;  i >= 0; i--) {
            downUpdata(i);
        }
    }
}
time_heap::~time_heap() {
    for (int i = 0; i < cur_size; i++) {
        delete array[i];
    }
    delete[] array;
}
heap_timer* time_heap::top() const {
    if (empty()) return nullptr;
    return array[0];
}
void time_heap::add_timer(heap_timer *timer) throw(std::exception()) {
    if (!timer) return ;
    if (cur_size > capacity) {
        resize();
    }
    int hole = cur_size++;
    int parent = 0;
    for (; hole > 0; hole = parent) {
        parent = (hole - 1) / 2;
        if (array[parent]->expire <= timer->expire) {
            break;
        }
        array[hole] = array[parent];
    }
    array[hole] = timer;
}
void time_heap::del_timer(heap_timer *timer) {
    if (!timer) return ;
    timer->cb_func;
}
void time_heap::pop_timer() {
    if (empty()) return ;
    if (array[0]) {
        delete array[0];
        array[0] = array[--cur_size];
        downUpdata(0);
    }
}
void time_heap::tick() {
    heap_timer *tmp = array[0];
    time_t cur = time(NULL);
    while (!empty()) {
        if (!tmp) break;
        if (tmp->expire > cur) {
            break;
        }
        if (array[0]->cb_func) {
            array[0]->cb_func(array[0]->user_data);
        }
        pop_timer();
        tmp = array[0];
    }
}
bool time_heap::empty() const {
    return cur_size == 0;
}
void time_heap::downUpdata(int ind) {
    heap_timer *temp = array[ind];
    while ((ind * 2 + 1) <= (cur_size - 1)) {
        int child = ind * 2 + 1;
        if ((child + 1) <= (cur_size - 1) && array[child + 1]->expire < array[child]->expire) {
            child++;
        }
        if (array[child]->expire < temp->expire) {
            array[ind] = array[child];
        } else {
            break;
        }
        ind = child;
    }
    array[ind] = temp;
}
void time_heap::resize() throw(std::exception()) {
    heap_timer **temp = new heap_timer*[2 * capacity]{nullptr};
    if (temp) {
        throw std::exception();
    }
    this->capacity <<= 1;
    for (int i = 0; i < cur_size; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}


#endif