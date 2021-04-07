/*************************************************************************
	> File Name: 1.count.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月05日 星期一 19时16分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

struct Data {
    int count;
    int id;
    pthread_mutex_t mutex;
};

struct Data *alloc(int id) {
    struct Data *fp;
    if ((fp = malloc(sizeof(struct Data))) == NULL) {
        perror("malloc");
        return NULL;
    }
    fp->count = 1;
    fp->id = id;
    if (pthread_mutex_init(&fp->mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        free(fp);
        return NULL;
    }
    return fp;

}
void hold(struct Data *fp) {
    pthread_mutex_lock(&fp->mutex);
    fp->count++;
    pthread_mutex_unlock(&fp->mutex);
}

void rele(struct Data *fp) {
    pthread_mutex_lock(&fp->mutex);
    if (fp == NULL) return ;
    if (--fp->count == 0) {
        pthread_mutex_unlock(&fp->mutex);
        pthread_mutex_destroy(&fp->mutex);
        free(fp);
        fp = NULL;
    }
    pthread_mutex_unlock(&fp->mutex);
}


int main() {
    struct Data *fp = alloc(1);
    for (int i = 0; i < 10; i++) {
        int val = rand() % 2;
        if (val & 1) {
            hold(fp); 
        } else {
            rele(fp);
        }
    }
    return 0;
}
