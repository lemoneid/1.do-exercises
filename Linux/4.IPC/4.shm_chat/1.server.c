/*************************************************************************
	> File Name: 1.server.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 09时19分51秒
 ************************************************************************/

#include "head.h"
#include "chat.h"

struct Message *share_memory = NULL;

void *print(int signum) {
    pthread_mutex_lock(&share_memory->mutex);
    printf(RED"<%s>"NONE " : %s\n", share_memory->name, share_memory->msg);
    memset(share_memory->name, 0, sizeof(share_memory->name));
    memset(share_memory->msg, 0, sizeof(share_memory->msg));
    pthread_mutex_unlock(&share_memory->mutex);
}

int main() {
    int shmid;
    key_t key = ftok(".", 2011);

    if ((shmid = shmget(key, sizeof(struct Message), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }

    if ((share_memory = (struct Message *)shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }

    memset(share_memory, 0, sizeof(struct Message));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&share_memory->mutex, &attr);
    
    share_memory->pid = getpid();
    while (1) {
        signal(SIGUSR2, (void *)print);
        //pause()会令目前的进程暂停(进入睡眠状态), 直到被信号(signal)所中断。
        pause();
    }
    return 0;
}
