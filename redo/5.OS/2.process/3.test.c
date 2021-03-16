/*************************************************************************
	> File Name: 3.test.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 14时05分35秒
 ************************************************************************/

#include "head.h" 

#define filename "temp"

int m_flag = 0;
int main(int argc, char **argv) {
    int opt;
    pid_t pid;
    char *msg = NULL;
    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
            case 'm':
                m_flag = 1;
                msg = strdup(optarg);
                break;
            default:
                fprintf(stderr,"Usage: %s [-m message]\n", argv[0]);
                exit(1);
        }
    }
    if (m_flag) {
        if (msg) {
            printf("%s\n", msg);
            free(msg);
        }
        return 0;
    }
    
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    }
    if (pid == 0) {
        execlp("vim", "vim", filename, NULL);
    } else {
            wait(NULL);
            if (access(filename, R_OK) != 0) {
                perror("access error");
                exit(1);
            }
            if((pid = fork()) < 0) {
                perror("fork error");
                exit(1);
            }
            if (pid == 0) {
                //printf("cat!\n");
                execlp("cat", "cat", filename, NULL);
            } else {
                wait(NULL);
                //printf("rm\n");
                execlp("rm", "rm", filename, NULL);
            }
    }

    return 0;
}

