/*************************************************************************
	> File Name: thread_pool.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 11时15分45秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <queue>
#include <algorithm>
#include <condition_variable>

namespace worst {
class Task {
public :
    template<typename Func_T, typename ...ARGS> 
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...); 
    }
    void run() {
        func();
    }
private :
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int size = 5);
    void start();
    void stop();
    ~ThreadPool();
    template<typename Func_T, typename ...ARGS>
    void add_one_task(Func_T f, ARGS ...args);
private :
    void thread_loop();
    void __add_one_task(Task *);
    void __stop_set_false();
    Task *get_one_task();
    std::mutex m_mutex_;
    std::condition_variable m_cond_;
    std::vector<std::thread *> threads_;
    std::queue<Task *> tasks_;
    int size_;
    volatile bool is_started_;
};

ThreadPool::ThreadPool(int size) : size_(size), is_started_(false), m_mutex_(), m_cond_() {}

void ThreadPool::start() {
    std::unique_lock<std::mutex> lock(m_mutex_);
    is_started_ = true;
    for (int i = 0; i < size_; ++i) {
        threads_.push_back(new std::thread(&ThreadPool::thread_loop, this));
    }
}

template<typename Func_T, typename ...ARGS>
void ThreadPool::add_one_task(Func_T f, ARGS ...args) {
    __add_one_task(new Task(f, std::forward<ARGS>(args)...));
    return ;
}

void ThreadPool::__add_one_task(Task *t) {
    std::unique_lock<std::mutex> lock(m_mutex_);
    tasks_.push(t);
    m_cond_.notify_one();
    return ;
}

void ThreadPool::thread_loop()  {
    while (is_started_) {
        Task *t = get_one_task();
        if (t != nullptr) {
            std::cout << "tid = " << std::this_thread::get_id() << std::endl; 
            t->run();
        }
        std::cout.flush();
        std::cout << "is_started_ = " << is_started_ << std::endl; 
    }
}

Task *ThreadPool::get_one_task() {
    std::unique_lock<std::mutex> lock(m_mutex_);
    while (tasks_.empty() && !is_started_) {
        m_cond_.wait(lock);
    }
    Task *t = nullptr;
    if (!tasks_.empty() && is_started_) {
        t = tasks_.front();
        tasks_.pop();
    }
    return t;
}

void ThreadPool::__stop_set_false() {
    std::cout << "---in set_false----" << std::endl;
    std::unique_lock<std::mutex> lock(m_mutex_);
    std::cout << "---lock set_false----" << std::endl;
    is_started_ = false;
    m_cond_.notify_all();
    return ;
}

void ThreadPool::stop() {
    __stop_set_false();
    std::unique_lock<std::mutex> lock(m_mutex_);
    std::cout << "---lock stop----" << std::endl;
    for (int i = 0; i < threads_.size(); ++i) {
        //std::cout << "---" << i << "----" << std::endl;
        threads_[i]->join();
        delete threads_[i];
    }
    threads_.clear();
    return ;
}
  
ThreadPool::~ThreadPool() {
    stop();
    return ;
}

}


#endif
