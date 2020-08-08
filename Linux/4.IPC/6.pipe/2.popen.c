/*************************************************************************
	> File Name: 2.popen.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 14时16分36秒
 ************************************************************************/

#include "head.h"

int main() {
    FILE *fp, *fw;
    fw = fopen("./.w", "w");
    char buffer[1024];
    fp = popen("ls /etc", "r");
    size_t read;
    if (fp == NULL) {
        perror("fp NULL");
        exit(1);
    }
    while ((read = fread(buffer, sizeof(buffer), 1, fp)) >= 0) {
        //printf("%s\n", buffer);
        fwrite(buffer, strlen(buffer), 1, fw);
        memset(buffer, 0, sizeof(buffer));
        if (feof(fp)) break;
    }
    fclose(fw);
    pclose(fp);

    return 0;
}
