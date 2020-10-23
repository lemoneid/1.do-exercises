/*************************************************************************
	> File Name: 3.add.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月02日 星期日 14时20分16秒
 ************************************************************************/

#include "head.h"

char num_file[] = "./.num";
char lock_file[] = "./.lock";

size_t set_num(int now, int sum) {
    FILE *fp = fopen(num_file, "w");
    char buffer[100] = {0};
    sprintf(buffer,"%d\n%d\n", now, sum);
    size_t nwrite = fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);
    return nwrite;
} 

size_t get_num(int *now, int *sum) {
    FILE *fp = fopen(num_file, "r");
    if (fp == NULL) {
        perror("fopen_r()");
        return -1;
    }

    char tmp_now[20] = {0};
    char tmp_sum[20] = {0};
    fgets(tmp_now, sizeof(tmp_now), fp);
    fgets(tmp_sum, sizeof(tmp_sum), fp);
    tmp_now[strlen(tmp_now) - 1] = '\0';
    tmp_sum[strlen(tmp_sum) - 1] = '\0';
    *now = atoi(tmp_now);
    *sum = atoi(tmp_sum);
    fclose(fp);
    return 0;
}

void do_add(int max, int x) {
    int sum = 0, now = 0;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&now, &sum) < 0) {
            fclose(lock);
            continue; 
        }
        DBG(GREEN"<Debug>"NONE " : <%d> now = %d, sum = %d\n", x, now, sum);
        if (now > max) {
            flock(lock->_fileno, LOCK_UN);
            break;
        }
        
        sum += now;
        now++;
        set_num(now, sum);
        flock(lock->_fileno, LOCK_UN);
    }
    return ;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }
    //atoi转译 str 所指的字节字符串中的整数值
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    int now = 0;
    int sum = 0;

    //save to File
    set_num(now, sum);

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
    get_num(&now, &sum);
    printf("sum = %d\n", sum);
    return 0;
}
