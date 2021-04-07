/*************************************************************************
	> File Name: 2.hash.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月05日 星期一 19时25分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#define NHASH 29
#define HASH(id) ((unsigned long)id % NHASH)

struct Data {
    int count;
    int id;
    struct Data *next;
    pthread_mutex_t mutex;
};

struct Data *data[NHASH];
pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

struct Data *init(int id) {
    struct Data *fp = NULL;
    int idx;
    if ((fp = malloc(sizeof(struct Data))) == NULL) {
        perror("malloc");
        return NULL;
    }
    fp->count = 1;
    if fpthread_mutex_init(&fp->mutrx, NULL) != 0) {
        perror("pthread_mutex_init");
        free(fp);
        fp = NULL;
        return NULL;
    }
    fp->id = id;
    idx = HASH(id);
    pthread_mutex_lock(&hashlock);
    fp->next = data[idx];
    data[idx] = fp;
    pthread_mutex_lock(&fp->mutex);
    pthread_mutex_unlock(&hashlock);
    //intializer
    pthread_mutex_lock(&fp->mutex);
    return fp;
}

void hold(struct Data *fp) {
    pthread_mutex_lock(&fp->mutex);
    if (fp == NULL) return ;
    fp->count++;
    pthread_mutex_unlock(&fp->mutex);
}

struct Data *find(int id) {
    struct Data *fp = NULL;
    pthread_mutex_lock(&hashlock);
    for (fp = data[HASH(fp->id)]; fp != NULL; fp = fp->next) {
        if (fp->id == id) {
            fp->count++;
            pthread_mutex_unlock(&hashlock);
            return fp;
        }
    }
    pthread_mutex_unlock(&hashlock);
    return NULL;
}

void rele(struct Data *fp) {
    if (fp == NULL) return ;
    struct Data *tfp = NULL;
    int idx;
    pthread_mutex_lock(&hashlock);
    if (--fp->count == 0) {
        idx = HASH(fp->id);
        if (data[idx] == fp) {
            data[idx] = fp->next;
        } else {
            for (tfp = data[idx]; tfp != NULL; tfp = tfp->next) {
                if (tfp->next == fp) {
                    tfp->next = fp->next;
                    break;
                }
            }
        }
        pthread_mutex_unlock(&hashlock);
        pthread_mutex_destroy(&fp->mutex);
        free(fp);
        fp = NULL;
        return ;
    }
    pthread_mutex_unlock(&hashlock);
    return ;
}

int main() {


    return 0;
}
