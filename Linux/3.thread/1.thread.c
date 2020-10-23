/*************************************************************************
	> File Name: 1.thread.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 18时19分04秒
 ************************************************************************/

#include "head.h"
 

void *print(void *arg) {
    //int tmp = *(int *)arg;
    //DBG(GREEN"<Debug>"NONE " : 我是第 %d 个子线程!\n", tmp);
    DBG(GREEN"<Debug>"NONE " : 我是第 %d 个子线程!\n", *(int*)arg);
}
 
int main(int argc, char **argv) {
    int tmp_arg[105] = {0};
    pthread_t tid[100];
    for (int i = 1; i < 100; ++i) {
        tmp_arg[i] = i;
        pthread_create(&tid[i], NULL, print, (void *)&tmp_arg[i]);
    }
    
    for (int i = 0; i < 100; ++i) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
