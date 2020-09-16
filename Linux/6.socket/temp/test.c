/*************************************************************************
	> File Name: test.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 16时25分41秒
 ************************************************************************/

#include "head.h"
#include "thread_pool.h"

#define SIZE 10 
#define THREADNUM 5 
#define BUFFSIZE 512

int main() {
    pthread_t tid[THREADNUM];
    struct task_queue taskQueue;
    taskQueue = *task_queue_init(&taskQueue, SIZE);
    
   char buff[SIZE][BUFFSIZE] = {0};
    for (int i = 0; i < THREADNUM; ++i) {
         int id =  pthread_create(&tid[i], NULL, thread_run, (void *)&taskQueue);
        //DBG(GREEN"<Debug>"NONE " : Created = %d\n", id);
    }
        DBG(GREEN"<Debug>"NONE " : Created success\n");

    int sub = 0;

    //压力测试
    while (1) {
        FILE *fp = fopen("./thread_pool.c", "r");
        if (fp == NULL) {
            perror("fopen()");
            exit(1);
        }
        while (fgets(buff[sub], BUFFSIZE, fp) != NULL) {
            task_queue_push(&taskQueue, buff[sub]);
            if (++sub >= SIZE) {
                sub = 0;
            }
        }
        fclose(fp);
    }
    //task_queue_clear(&taskQueue);
    for (int i = 0; i < THREADNUM; ++i) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

