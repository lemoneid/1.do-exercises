/*************************************************************************
	> File Name: 1.Healthv1.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月16日 星期五 18时42分41秒
 ************************************************************************/

#include "head.h"
#include "./health.h"

#define handle_error(msg)\
    do{perror(msg); exit(EXIT_FAILURE);} while(0);

struct Share *share_memory = NULL;

void doing_process(int who) {
    char msg[512] = {0};
    strcpy(msg, who ? "Salve" : "Master");
    printf("I'm %s\n", msg);
    return ;
}

void exe_master() {
    int pnum = 1;
    DBG(BLUE"The %dth Process act as a Salve!\n"NONE, pnum);
    while (1) {
        if (share_memory->type == 1) {
            pthread_mutex_lock(&share_memory->mutex);
            DBG(BLUE"Master Process Waiting for Sigal..\n"NONE);
            pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
            pthread_mutex_unlock(&share_memory->mutex);
            while (1) {
                if (share_memory->type == 1) {
                    break;
                }
                sleep(2);
                doing_process(0);
            }
        } else {
            while (1) {
                if (share_memory->type == 1) break;
                sleep(2);
                doing_process(0);
            }
        }
    }
}

void exe_salve() {
    int pnum = 2;
    DBG(BLUE"The %dth Process act as a Salve!\n"NONE, pnum);
    while (1) {
        if (share_memory->type == 0) {
            pthread_mutex_lock(&share_memory->mutex);
            DBG(BLUE"Salve Process Waiting for Sigal..\n"NONE);
            pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
            pthread_mutex_unlock(&share_memory->mutex);
            while (1) {
                if (share_memory->type == 0) {
                    break;
                }
                sleep(2);
                doing_process(1);
            }
        } else {
            while (1) {
                if (share_memory->type == 0) break;
                sleep(2);
                doing_process(1);
            }
        }
    }
}

int main() {
    int who = 0, shmid;
    DBG(GREEN"Start..\n"NONE);
    key_t key = ftok(".", 209);
    if ((shmid = shmget(key, sizeof(struct Share), IPC_CREAT | 0666)) < 0) {
       handle_error("shmget()"); 
    }
    DBG(GREEN"Shmget success...\n"NONE);
    if ((share_memory = (struct Share *)shmat(shmid, NULL, 0)) == NULL) {
        handle_error("shmat()");
    }
    DBG(GREEN"Shmat success...\n"NONE);
    
    memset(share_memory, 0, sizeof(struct Share));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&share_memory->mutex, &attr);
    DBG(GREEN"Init mutex...\n"NONE);

    pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&share_memory->cond, &cond_attr);
    DBG(GREEN"Init condition...\n"NONE);

    share_memory->type = 0;
    DBG(GREEN"Program set to be Master default..\n"NONE);
    DBG(GREEN"Forking...\n"NONE);
    pid_t pid;
    
    int curp = 0;
    for (int i = 0; i < 2; ++i) {
        if ((pid = fork()) < 0) {
            handle_error("fork()");
        }
        curp =  i;
        if (pid == 0) break;
    }
    if (pid == 0) {
        
        if (curp == 0) exe_master();
        if (curp == 1) exe_salve();

    } else {
        int pnum = 0;
        DBG(BLUE"The %dth Process act as a Salve!\n"NONE, pnum);
        while(1) {
            int cmd;
            DBG(YELLOW"Please Input You Cmd( 0 for Master, 1 for Salve)\n"NONE);
            scanf("%d", &cmd);
            if (cmd == 0) {
                share_memory->type = 0;
            } else {
                share_memory->type = 1;
            }
            pthread_cond_signal(&share_memory->cond);
        }
        wait(NULL);
    }


    return 0;
}
