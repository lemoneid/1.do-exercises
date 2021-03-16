/*************************************************************************
	> File Name: 4.add.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 14时56分23秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Num {
    int now;
    int sum;
};

size_t set_num(struct Num *num) {
    FILE *fp = fopen(num_file, "w");
    if (fp == NULL) {
        perror("fopen()");
        return -1;
    }
    size_t nwrite = fwrite(num, sizeof(struct Num), 1, fp);
    fclose(fp);
    return nwrite;
}

size_t get_num(struct Num *num) {
    FILE *fp = fopen(num_file, "r");
    if (fp == NULL) {
        perror("fopen()");
        return -1;
    }
    size_t nread = fread(num, sizeof(struct Num), 1, fp);
    fclose(fp);
    return nread;
}


void do_add(int max, int x) {
    struct Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        // 关闭文件,锁也关闭
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        DBG(GREEN"<Debug>"NONE" ; <%d> now = %d, sum = %d\n", x, num.now, num.sum);
        if (num.now > max) {
            break;
        }
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
    
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }
    
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    struct Num num;
    pid_t pid;
    int x;
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    for (int i = 0; i < ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    }
    if (pid == 0)  {
        do_add(max, x);
        exit(0);
    } else {
        for (int i = 0; i < ins; i++)  {
            wait(NULL);
        }
    }
    get_num(&num);
    printf("sum = %d\n", num.sum);
    return 0;
}
