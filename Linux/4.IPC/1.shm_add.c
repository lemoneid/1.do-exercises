/*************************************************************************
	> File Name: 1.shm_add.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月02日 星期日 15时41分34秒
 ************************************************************************/

#include "head.h"

struct Num {
    int now, sum;
    pthread_mutex_t mutex;
};

struct Num *share_memory;


void do_add(int max, int x) {
    while(1) {
        //先判断,加解锁
        //lock
        pthread_mutex_lock(&share_memory->mutex);
        DBG(GREEN"<Debug>"NONE " : <%d> now = %d, sum = %d\n", x, share_memory->now, share_memory->sum);

        if (share_memory->now > max) {
            //unlock
            pthread_mutex_unlock(&share_memory->mutex);
            break;
        }
        share_memory->sum += share_memory->now;
        share_memory->now++;

        //unlock
        pthread_mutex_unlock(&share_memory->mutex);
    }
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ints\n", argv[0]);
    }
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    pid_t pid;
    int shmid;
    key_t key = ftok(".", 2009);
    if ((shmid =shmget(key, sizeof(struct Num), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }

    if ((share_memory = (struct Num *)shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }
    
    memset(share_memory, 0, sizeof(struct Num));
    //锁属性
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    
    //对锁属性更改,让线程锁可以在进程间共享
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    //初始化锁
    pthread_mutex_init(&share_memory->mutex, &attr);
    
    int x = 0;
    for (int i = 0; i < ins; ++i) {
        if (pid = fork() < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    }
    
    if (pid == 0) {
        
        do_add(max, x);
        exit(0);
    }
    
    while (ins--) {
        wait(NULL);
    }

    return 0;
}
