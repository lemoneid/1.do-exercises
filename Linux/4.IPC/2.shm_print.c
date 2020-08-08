/*************************************************************************
	> File Name: 1.shm_add.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月02日 星期日 15时41分34秒
 ************************************************************************/

#include "head.h"


struct Data {
    char str[1000];
    pthread_mutex_t mutex;
};

struct Data *share_memory;

void do_print() {
    while (1) {
        while (strlen(share_memory->str)) {
            pthread_mutex_lock(&share_memory->mutex);
            DBG(GREEN"<Debug>"NONE " : locked in Parent\n");
            printf(RED"<Parent>"NONE " : %s\n ", share_memory->str);
            memset(share_memory->str, 0, sizeof(share_memory->str));
            pthread_mutex_unlock(&share_memory->mutex);
        }
    }
}

int main(int argc, char **argv) {
    pid_t pid;
    int shmid;
    key_t key = ftok(".", 209);
    if ((shmid =shmget(key, sizeof(struct Data), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }

    if ((share_memory = (struct Data *)shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    //初始化锁
    pthread_mutex_init(&share_memory->mutex, &attr);

    memset(share_memory->str, 0, sizeof(share_memory->str));
    if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
    }

   if (pid == 0) {
       while (1) {
           //造成cpu空转
            if (strlen(share_memory->str)) continue;
            pthread_mutex_lock(&share_memory->mutex);
            DBG(GREEN"<Debug>"NONE " : locked in child\n");
            scanf("%[^\n]s", share_memory->str);
            getchar(); 
            printf(YELLOW"<child>"NONE " : %s\n ", share_memory->str);
            pthread_mutex_unlock(&share_memory->mutex);
            //usleep(20);
       }
        //exit(0);
   }  else {
       do_print();
       wait(NULL);
   }
    
    return 0;
}
