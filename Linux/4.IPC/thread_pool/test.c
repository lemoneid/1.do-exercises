/*************************************************************************
	> File Name: test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 16时25分41秒
 ************************************************************************/

#include "head.h"
#include "thread_pool.h"

#define SIZE 50
#define THREADNUM 5
#define BUFFSIZE 512

int main() {
    pthread_t tid[THREADNUM];
    struct task_queue taskQueue;
    taskQueue = *task_queue_init(&taskQueue, SIZE);
    DBG(GREEN"<Debug>"NONE " :head = %d. tail = %d, cnt = %d, size = %d\n", taskQueue.head, taskQueue.tail ,taskQueue.cnt, taskQueue.size);
    
    for (int i = 0; i < THREADNUM; ++i) {
         int id =  pthread_create(&tid[i], NULL, thread_run, (void *)&taskQueue);
        //DBG(GREEN"<Debug>"NONE " : Created = %d\n", id);
    }
        DBG(GREEN"<Debug>"NONE " : Created success\n");

    while (1) {
        char buff[BUFFSIZE] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        DBG(GREEN"<stdin>"NONE "before : %s\n", buff);
        task_queue_push(&taskQueue, buff);
        DBG(GREEN"<stdin>"NONE "after : %s\n", buff);
        sleep(1);
    }
    task_queue_clear(&taskQueue);
    for (int i = 0; i < THREADNUM; ++i) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

