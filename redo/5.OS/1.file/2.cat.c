/*************************************************************************
	> File Name: 2.cat.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 20时13分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>


void read_file(char *pathname);
int n = 1, flag = 0;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage : %s file...\n", argv[0]);
    }

    int opt;
    flag = 0;
    while ((opt = getopt(argc, argv, "n")) != -1) {
        switch (opt) {
            case 'n': flag = 1; break;
            default : fprintf(stderr, "Usage: [-n] file..."); exit(1);
        }
    }
    argc -= optind;
    argv += optind;
    for (int i = 0; i < argc; i++) {
        read_file(argv[i]);
    }
    return 0;
}

void read_file(char *pathname) {
    FILE *file = NULL;
    char buff[1024] = {0};
    if ((file = fopen(pathname, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buff, sizeof(buff), file) != NULL) {
        if (flag) printf("%d ", n++);
        printf("%s", buff);
        memset(buff, 0, sizeof(buff));
    }
}
