/*************************************************************************
	> File Name: 2.git.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 13时41分31秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int main(int argc, char **argv) {
    int opt, m_flag = 0;
    char *msg = NULL;
    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
            case 'm' :
                m_flag = 1;
                msg = strdup(optarg);
                break;
            default :
                fprintf(stderr, "Usage : %s -m msg", argv[0]);
                exit(1);
                break;
        }
    }
    DBG(GREEN"<Debug>"NONE " : m = %d\n", m_flag);

    if (m_flag == 1) {
        printf("%s", msg);
        if (msg) free(msg);
        msg = NULL;
        return 0;
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("vim", "vim", "./tmp.txt", NULL);
    } else {
        wait(NULL);
        execl("/bin/cat", "cat", "./tmp.txt", NULL);
    }
    return 0;
}
