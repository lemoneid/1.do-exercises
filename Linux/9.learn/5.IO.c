/*************************************************************************
	> File Name: 5.IO.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月05日 星期一 21时52分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_N 50000

char buff[MAX_N];

void make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl");
        return ;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
    return ;
}

void make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return ;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}


int main() {
    int total, nwrite;
    char *ptr;
    total = read(STDIN_FILENO, buff, sizeof(buff));
    fprintf(stderr, "read %d bytes\n", total);
    ptr = buff;
    make_nonblock(STDOUT_FILENO);
    while (total > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, total);
        if (nwrite < 0) {
            perror("write");
        }
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        if (nwrite <= 0) continue;
        total -= nwrite;
        ptr += nwrite;
    }
    make_block(STDOUT_FILENO);
    return 0;
}
