/*************************************************************************
	> File Name: 2.sem_thread.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月24日 星期四 12时39分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>


#define P sem_wait
#define V sem_post 
#define full_apple &fullA
#define full_orange &fullB
#define empty &empty_aha


sem_t fullA;
sem_t fullB;
sem_t empty_aha;
int num=0; 



void* Dad(void *p)
{
    while(num<50)
    { 
        P(empty);  
	    num++;
        printf("老爸放了个苹果%d\n",num);
        V(full_apple);
    }
}


void* Dangter(void *p)
{
    while(num<50)
    {
        P(full_apple);
		num++;               
         printf("女儿吃了个苹果%d\n",num);
        V(empty);
    }
}

void* Mum(void *p)
{
    while(num<50)
    { 
        P(empty);  
	    num++;
        printf("老妈放了个橘子%d\n",num);
        V(full_orange);
    }
}


void* Son(void *p)
{
    while(num<50)
    {
        P(full_orange);
		num++;               
        printf("儿子吃了个橘子%d\n",num);
        V(empty);
    }
}

int main()
{
    
    sem_init(full_apple, 0, 0);
    sem_init(full_orange, 0, 0);   
    sem_init(empty, 0, 1);   
 
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_create(&tid0, NULL, Dad, NULL);
    pthread_create(&tid1, NULL, Mum, NULL);
    pthread_create(&tid2, NULL, Son, NULL);
    pthread_create(&tid3, NULL, Dangter, NULL);
    getchar();
    pthread_exit(0);
    return 0;
}
