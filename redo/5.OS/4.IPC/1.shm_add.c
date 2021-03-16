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
};

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }

    int max = atoi(argv[1]);
    int ind = atoi(argv[2]);
    pid_t pid;
    int shmid;
    key_t key = ftok(".", 2009);

    if ((shmid = shmget(key, )))

    return 0;
}
