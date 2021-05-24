/*************************************************************************
	> File Name: fork.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月27日 星期二 14时15分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    int fd;
    if ((fd = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, 0666)) < -1) {
        perror("open");
        exit(1);
    }
    int pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    ssize_t nwrite = 0;
    char buff[512];
    if (pid == 0) {
        cout << " child start" << endl;
        for (int i = 0; i < 10000; i++) {
            memset(buff, 0, sizeof(buff));
            sprintf(buff, "child : this is %d , the pid = %d\n", i, getpid());
            nwrite = write(fd, buff, strlen(buff));
            if (nwrite < 0) {
                perror("child : write");
            }
        }
        return 0;
    } else if (pid > 0) {
        cout << " father start" << endl;
        for (int i = 0; i < 10000; i++) {
            memset(buff, 0, sizeof(buff));
            sprintf(buff, "father : this is %d , the pid = %d\n", i, getpid());
            nwrite = write(fd, buff, strlen(buff));
            if (nwrite < 0) {
                perror("father : write");
            }
        }
    }
    close(fd);
    return 0;
}
