/*************************************************************************
	> File Name: 2.multi_process.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 12时59分20秒
 ************************************************************************/

#include "head.h" 

int main(int argc, char **argv) {
    pid_t pid;
    char sum[20], now[20];
    int cur, ans;
    int x = 0;
    for (int i = 0; i < 5; ++i) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        x = i;
        if (pid == 0) break;
    } 
    if (pid == 0) {
        FILE *fp;
        fp = fopen("/tmp.tex",rw);
        fgets(now, 20, fp);
        fgets(sum, 20, fp);
        sprintf(cur, "%d", now);
        sprintf(ans, "%d", now);
        while (1) {
            if (now > 1000) {
                break;
            }
            ans += cur++;
        }
        sprintf(now, "%s", cur);
        sprintf(sum, "%s", ans);
        fputs(now, 20, fp);
        fputs(sum, 20, fp);
        fclose(fp);

    } else {
        for (int i = 0; i < x; ++i) {
            wait(NULL);
        }
    }

    return 0;
}

