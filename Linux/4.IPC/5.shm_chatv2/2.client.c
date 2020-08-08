/*************************************************************************
	> File Name: 2.client.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 09时35分56秒
 ************************************************************************/

#include "head.h"
#include "chat.h"

struct Message *share_memory = NULL;

int main(int argc, char **argv) {
    struct Message tmp;
    int opt;
    //"n:" 代表有参
    //optarg是getopt的三个全局变量之一,代表紧跟参数
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
            case 'n' :
                strcpy(tmp.name, optarg);
                break;
            default :
                fprintf(stderr, "Usage : %s -n name!\n", argv[0]);
                exit(1);
                break;
        }
    }
    
    if (argc < 3) {
        fprintf(stderr, "Usage : %s -n name!\n", argv[0]);
        exit(1);
    }

    int shmid;
    key_t key = ftok(".", 2011);
    if ((shmid = shmget(key, sizeof(struct Message), IPC_CREAT | 0666)) < 0) {
        perror("shmget()");
        exit(1);
    }

    if ((share_memory = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat()");
        exit(1);
    }
    
    while(1) {
        scanf("%[^\n]s", tmp.msg);
        getchar();
        if (!strlen(tmp.msg)) continue;
        while (1) {
            //隐性bug msg为空,多个client端同时上锁
            if (!strlen(share_memory->msg)) {
                pthread_mutex_lock(&share_memory->mutex);
                break;
            }
        }
        strcpy(share_memory->name, tmp.name);
        strcpy(share_memory->msg, tmp.msg);
        pthread_mutex_unlock(&share_memory->mutex);
        //kill(share_memory->pid, SIGUSR2);
        pthread_cond_signal(&share_memory->cond);
        DBG(GREEN"<Debug>"NONE" : AFTER signal\n");
        memset(tmp.msg, 0, sizeof(tmp.msg));
    }

}

