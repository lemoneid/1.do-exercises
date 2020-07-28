/*************************************************************************
	> File Name: 3.cp.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月26日 星期日 18时15分02秒
 ************************************************************************/

#include "head.h"
#define MAX_BUFFER 1024

int main(int argc, char ** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage : %s src dest\n", argv[0]);
        exit(1);
    }
    
    int fd_in, fd_out;
    
    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror("fopen()");
        exit(1);
    }
    
    if ((fd_out = creat(argv[2], 0666)) == -1) {
        perror("creat()");
        exit(1);
    }
        
    ssize_t nread;
    char buff[MAX_BUFFER + 5] = {0};
    while ((nread = read(fd_in, buff, MAX_BUFFER)) > 0) {
        DBG(GREEN"<Debug>"NONE" MAX_BUFFER = %d, nread = %d", MAX_BUFFER, nread);
        if (write(fd_out, buff, strlen(buff)) != nread) {
            perror("write()");
            exit(1);
        }
        memset(buff, 0, sizeof(buff));
    }

    return 0;
}
