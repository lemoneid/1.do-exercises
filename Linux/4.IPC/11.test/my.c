/*************************************************************************
	> File Name: client.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月11日 星期日 14时46分52秒
 ************************************************************************/

#include "head.h"
#define handle_error(msg)\
    do{perror(msg);exit(EXIT_FAILURE);}while(0);

struct msg {
    int condition;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_cond_t cond_master;
};
struct msg *share_memory;

void out_master() {
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        pthread_cond_wait(&share_memory->cond_master, &share_memory->mutex);
        printf("I'm Master\n");
        pthread_mutex_unlock(&share_memory->mutex);
        sleep(1);
    }
}
void out_client() {
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
        printf("I'm client\n");
        pthread_mutex_unlock(&share_memory->mutex);
        sleep(1);
    }
}
int main() {
    pid_t pid;
    int shmid;
    int op;
    key_t key = ftok(".", 2008);
    if ((shmid =shmget(key, sizeof(struct msg), IPC_CREAT | 0665)) < 0) {
        handle_error("shmget()");
    }
    if ((share_memory = (struct msg *)shmat(shmid, NULL, 0)) == NULL) {
        handle_error("shmat()");
    }
    memset(share_memory, 0, sizeof(share_memory));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&share_memory->mutex, &attr);
    pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&share_memory->cond, &cond_attr);
    pthread_cond_init(&share_memory->cond_master, &cond_attr);

    int x = 0;
    for (int i = 0; i < 2; ++i) {
        if ((pid = fork()) < 0) {
            handle_error("fork()");
        }
        x = i;
        if (pid == 0) break;
    }
    if (pid == 0) {
        if (x == 0) out_client();
        if (x == 1) out_master();
    } else {
        while (1) {
            scanf("%d", &op);
            if (op == 1) {
                pthread_cond_signal(&share_memory->cond_master);
            }
            pthread_cond_signal(&share_memory->cond);
            //pthread_mutex_unlock(&share_memory->mutex);
        }
        wait(NULL);
    }
    return 0;
}

