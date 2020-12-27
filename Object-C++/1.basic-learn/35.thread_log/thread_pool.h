/*************************************************************************
	> File Name: thread_poll.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 15时04分01秒
 ************************************************************************/

#ifndef _THREAD_POLL_H
#define _THREAD_POLL_H

#include <functional>
#include <thread>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <condition_variable>
#include <mutex>
namespace worst {
class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...); //解决参数类型引用的问题
    }
    void run() {
        func();
    }
private :
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int thread_size = 5);
    void start(); 
    void stop();
    template<typename Func_T, typename ...ARGS>
    void add_one_task(Func_T f, ARGS ...args) {
        std::unique_lock<std::mutex> lock(m_queue_mutex);
        __add_one_task(new Task(f, std::forward<ARGS>(args)...));
    }
    void __add_one_task(Task *);
    void stop_until_empty();
    ~ThreadPool();

private :
    void thread_loop();
    Task *get_one_task();
    int thread_size;
    volatile bool is_started;
    std::vector<std::thread *>Threads;
    std::queue<Task *> Tasks;
    std::mutex m_mutex;
    std::mutex m_mutex2;
    std::mutex m_queue_mutex;
    std::condition_variable m_cond;
    std::condition_variable m_queue_cond;
};

ThreadPool::ThreadPool(int thread_size) : 
    thread_size(thread_size), 
    is_started(false), 
    m_mutex(), 
    m_mutex2(), 
    m_queue_mutex(), 
    m_cond(), 
    m_queue_cond(){
}

void ThreadPool::start() {
    //std::unique_lock<std::mutex> lock(m_queue_mutex);
    std::unique_lock<std::mutex> lock(m_mutex);
    is_started = true;
    for (int i = 0; i < thread_size; ++i) {
        Threads.push_back(new std::thread(&ThreadPool::thread_loop, this));
    }    
}

void ThreadPool::stop_until_empty() {
    std::unique_lock<std::mutex> lock1(m_mutex2); 
    std::unique_lock<std::mutex> lock2(m_queue_mutex); 
    while (!Tasks.empty()) {
        m_queue_cond.wait(lock1); //释放锁
    }
    stop();
    
}

void ThreadPool::stop() {
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        //std::unique_lock<std::mutex> lock(m_queue_mutex);
        is_started = false;
        m_cond.notify_all();
    }   
    for (int i = 0; i < Threads.size(); ++i) {
        Threads[i]->join();
        delete Threads[i];
    }    
    Threads.clear();
    return ;
}

void ThreadPool::thread_loop() {
    while (is_started) {
        Task *t = get_one_task(); //没任务就等待,而不是占用资源
        if (t != nullptr) {
            //std::cout << "thread_loop tid : " << std::this_thread::get_id() << std::endl;
            t->run();
        }
    }
}
ThreadPool::~ThreadPool() {
    this->stop();
    return ;
}

Task *ThreadPool::get_one_task() {
    std::unique_lock<std::mutex>  lock(m_mutex);
    while (Tasks.empty() && is_started) {
        m_cond.wait(lock);
    }
    Task *t = nullptr;
    if (!Tasks.empty() && is_started) {
        t = Tasks.front();
        Tasks.pop();
        if (Tasks.empty()) {
            std::unique_lock<std::mutex> lock2(m_mutex2);
            m_queue_cond.notify_all(); // m_mutex没有任务写入,队列为空
        }
    }
    return t;
}

void ThreadPool::__add_one_task(Task * t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    Tasks.push(t);
    m_cond.notify_one();
    return ;
}

}

#endif
