/*************************************************************************
	> File Name: 2.multi_process.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 12时59分20秒
 ************************************************************************/

#include "head.h" 

#define filename "temp"

int m_flag = 0;
int main(int argc, char **argv) {
    int opt;
    pid_t pid;
    while ((opt = getopt(argc, argv, "m")) != -1) {
        switch (opt) {
            case 'm':
                m_flag = 1;
                break;
                break;
            default:
                fprintf(stderr,"Usage: %s [-m message]\n", argv[0]);
                exit(1);
        }
    }

    if (argc == 2) {
        printf("Usage: %s [-m message]\n", argv[0]);
        exit(1);
    }
   // argc -= optind;
    argv += optind; 
    if (m_flag) {
        printf("%s\n", *argv);
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

