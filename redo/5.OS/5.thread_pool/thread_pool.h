/*************************************************************************
	> File Name: thread_pool.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月18日 星期四 15时15分59秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

struct task_queue {
    int size, total, head, tail;
    char **data;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};



#endif
