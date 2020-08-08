/*************************************************************************
	> File Name: 3.add.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月02日 星期日 14时20分16秒
 ************************************************************************/

#include "head.h"

struct Num {
    int now, sum;
};

char num_file[] = "./.num";
char lock_file[] = "./.lock";

size_t set_num(struct Num *num) {
    FILE *fp = fopen(num_file, "w");
    size_t nwrite = fwrite(num, sizeof(struct Num), 1, fp);
    fclose(fp);
    return nwrite;
} 

size_t get_num(struct Num *num) {
    FILE *fp = fopen(num_file, "r");
    if (fp == NULL) {
        fclose(fp);
        perror("fopen_r()");
        return -1;
    }
    size_t nread = fread(num, sizeof(struct Num), 1,  fp);
    fclose(fp);
    if (nread < 0) {
        return -1;
    }
    return nread;
}

void do_add(int max, int x) {
    struct Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue; 
        }
        DBG(GREEN"<Debug>"NONE " : <%d> now = %d, sum = %d\n", x, num.now, num.sum);
        if (num.now > max) {
            flock(lock->_fileno, LOCK_UN);
            break;
        }
        
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
    }
    return ;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    struct Num num;
    num.now = 0;
    num.sum = 0;

    //save to File
    set_num(&num);

    pid_t pid;
    int x;
    for (int i = 0; i < ins; ++i) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    }
        
    if (pid == 0) {
        //do add
        do_add(max, x);
        exit(0);
    }
    
    for (int i = 0; i < ins; ++i) {
        wait(NULL);
    }
    
    // read from File
    get_num(&num);
    printf("sum = %d\n", num.sum);
    return 0;
}
