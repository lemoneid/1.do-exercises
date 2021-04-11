/*************************************************************************
	> File Name: 2.select.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月11日 星期日 20时50分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc <= 2) {
        fprintf(stderr, "usage : %s ip port\n", argv[0]);
        exit(0);
    }
    const char *ip = argv[1]; 
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    return 0;
}
