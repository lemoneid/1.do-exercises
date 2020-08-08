/*************************************************************************
	> File Name: cat.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月05日 星期三 20时27分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char *pathname);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage : %s file..\n", argv[0]);
        exit(1);
    }

    for (int i = 1;i  < argc; ++i)  {
        printf("%s\n", argv[i]);
        read_file(argv[i]);
    }

    return 0;
}

void read_file(char *pathname) {
    FILE *file  = NULL;
    char buff[1024] = {0};
    if ((file = fopen(pathname, "r")) == NULL) {
        perror("fopen()");
        exit(1);
    }
    
    while (fgets(buff, sizeof(buff), file) != NULL) {
        printf("%s", buff);
        memset(buff, 0, sizeof(buff));
    }


    return ;
}
