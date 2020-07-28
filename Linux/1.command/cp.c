/*************************************************************************
	> File Name: cp.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月26日 星期日 16时18分19秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define COPYMODE 0664
#define BUFFER 4096

void copy(int fd_in, int fd_out) {
    char buffer[BUFFER];
    ssize_t size;
    while (size = read(fd_in, buffer, BUFFER)) {
        if (write(fd_out, buffer, size) != size) {
            perror("write error");
            exit(1);
        }
    }
    if (size < 0) {
        perror("read error");
        exit(1);
    }
}


int main(int argc, char **argv) {
    int fd_in, fd_out;
    if (argc != 3) {
        fprintf(stderr, "Usage %s file...", argv[0]);
        exit(1);
    }    
    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror("open error");
        exit(1);
    }
    if ((fd_out = creat(argv[2], COPYMODE)) == -1) {
        perror("create error");
        exit(1);
    }
    copy(fd_in, fd_out);
    return 0;
}

