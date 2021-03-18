/*************************************************************************
	> File Name: 1.shm_add.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 15时52分08秒
 ************************************************************************/

#include "head.h"

struct Num {
    int now;
    int sum;
    pthread_mutex_t mutex;
};

struct Num *share_memory;

void do_add(int max, int x) {
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        DBG(GREEN"<Debug>"NONE " : <%d> now = %d, sum = %d\n", x, share_memory->now, share_memory->sum);
        if (share_memory->now > max) {
            pthread_mutex_unlock(&share_memory->mutex);
            break;
        }
        share_memory->sum += share_memory->now;
        share_memory->now++;
        pthread_mutex_unlock(&share_memory->mutex);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }

    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    DBG("max = %d, ins = %d\n", max, ins);
    pid_t pid;
    int shmid;
    key_t key = ftok(".", 2009);
    if ((shmid = shmget(key, sizeof(struct Num), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }
    
    if ((share_memory = (struct Num *)shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }
    
    memset(share_memory, 0, sizeof(struct Num));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&share_memory->mutex, &attr);
    int x = 0;
    for (int i = 0; i < ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    }

    if (pid == 0) {
        do_add(max, x);
        exit(0);
    } else {
        for (int i = 0; i < ins; i++) {
            wait(NULL);
        }
    }
    return 0;
}
