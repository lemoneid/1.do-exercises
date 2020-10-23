/*************************************************************************
	> File Name: 1.thread.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 18时19分04秒
 ************************************************************************/

#include "head.h"


#define INS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int now = 1, sum = 0;

//线程个数与CPU线程数应统一

void *add(void *arg) {
    while (1) { 
        //先判断,要加锁,临界区尽可能小,锁的变量尽可能少;
        //互斥锁:访问前加锁,访问后解锁
        pthread_mutex_lock(&mutex);
        if (now > 1000) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("now = %d\n", now);
        sum += now;
        now++;
        pthread_mutex_unlock(&mutex);
        usleep(30);
    }   
} 

int main(int argc, char **argv) {
    int tmp_arg[5] = {0};
    pthread_t tid[5];
    for (int i = 0; i < 5; ++i) {
        tmp_arg[i] = i;
        pthread_create(&tid[i], NULL, add, NULL);
    }
    //join相当于wait,等待释放资源 
    for (int i = 0; i < 5; ++i) {
        pthread_join(tid[i], NULL);
    }
    printf("%d\n", sum);
    return 0;
}
