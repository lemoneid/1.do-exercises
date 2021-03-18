/*************************************************************************
	> File Name: 3.sigal.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 22时42分55秒
 ************************************************************************/


#include "head.h"

struct Data {
    char str[1000];
    pthread_mutex_t mutex;
};

Data *share_memory;

void *do_print(int signum) {
    printf(RED"<Parent>"NONE " : %s\n ", share_memory->str);
    memset(share_memory->str, 0, sizeof(share_memory->str));
    return NULL;
}

int main() {
    pid_t pid;
    int shmid;
    key_t key = ftok(".", 2008);
    if ((shmid = shmget(key, sizeof(Data), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }

    if ((share_memory = (struct Data *)shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }

    memset(share_memory, sizeof(share_memory), 0);
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid == 0) {
        while (1) {
            DBG(GREEN"<Debug>"NONE " : locked in child\n");
            scanf("%[^\n]s", share_memory->str);
            getchar();
            printf(YELLOW"<child>"NONE" : %s\n", share_memory->str);
            kill(getppid(), SIGUSR1);
        }
    } else {
        signal(SIGUSR1, (void *)do_print);
        wait(NULL);
    }

    return 0;
}
