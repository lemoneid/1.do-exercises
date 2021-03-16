/*************************************************************************
	> File Name: 3.cp.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 20时58分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_BUFF 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s src dest\n", argv[0]);
    }
    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        perror("fopen");
        exit(1);
    }
    ssize_t nread;
    char *buff[MAX_BUFF + 5];
    while (!feof(fp_in)) {
        nread = fread(buff, MAX_BUFF, 1, fp_in);
        if (fwrite(buff, MAX_BUFF, 1, fp_out) != nread) {
            perror("fwrite");
            exit(1);
        }
        bzero(buff, sizeof(buff));
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
