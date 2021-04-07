/*************************************************************************
> File Name: 6.pipe.c
> Author: yanzhiwei
> Mail: 1931248856@qq.com
> Created Time: 2021年04月07日 星期三 16时24分29秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


const char *file_path = "./3.clock.c";

int main(int argc, char **argv) {
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    int file;
    if ((file = open(file_path,O_RDONLY)) < 0) {
        perror("open");
        exit(1);
    }
    char buf[512];
    if (pid == 0) {    /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */
        while (read(pipefd[0], &buf, 1) > 0) {
             write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        return 0;
    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Reader will see EOF */
        if (write(pipefd[1], argv[1], strlen(argv[1])) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
        }
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }


    return 0;
}
