/*************************************************************************
	> File Name: my_popen.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 14时50分20秒
 ************************************************************************/

#include "head.h"

static pid_t *childpid = NULL;
static int max;


FILE *m_popen(const char *cmd, const char *type) {
    int pfd[2];
    pid_t pid;
    FILE *fp;
    if ((type[0] != 'r' || type[0] != 'w') && type[1] != '\0') {
        errno = EINVAL;
        return NULL;
    }
    
    if (childpid == NULL) {
        //取得系统文件,系统中每个用户能打开的最大文件数
        max = sysconf(_SC_OPEN_MAX);
        if ((childpid = (pid_t *)calloc(max, sizeof(pid_t))) == NULL) {
            return NULL;
        }
    }
    
    if (pipe(pfd) < 0) {
        return NULL;
    }

    if ((pid = fork()) < 0) {
        return NULL;
    }

    if (pid == 0) {
        //父进程读,子进程就要写
        if (type[0] == 'r') {
            close(pfd[0]);
            if (pfd[1] != STDOUT_FILENO) {
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[1]);
            }
        } else {
            close(pfd[1]);
            if (pfd[0] != STDIN_FILENO) {
                dup2(pfd[0], STDIN_FILENO);
                close(pfd[0]);
            } 

        }

        for (int i = 0; i < max; ++i) {
            if (childpid[i] > 0) {
                //
                close(i);
            }
        }

        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(0);
    }
    
    if (type[0] == 'r') {
        close(pfd[1]);
        if ((fp = fdopen(pfd[0], type)) == NULL)  {
            return NULL;
        } 
    } else {
        close(pfd[0]);
        if ((fp = fdopen(pfd[1], type)) == NULL) {
            return NULL;
        }
    }
    childpid[fileno(fp)] = pid;
    return fp;
}

int m_pclose(FILE *fp) {
    int status, fd, pid;
    if (childpid == NULL) {
        errno = EINVAL;
        return -1;
    }
    
    fd = fileno(fp);
    pid = childpid[fd];
    if (pid == 0) {
        errno = EINVAL;
        return -1;
    }
    childpid[fd] = 0;
    close(fd);
    waitpid(pid, &status, 0);
    return status;
}

