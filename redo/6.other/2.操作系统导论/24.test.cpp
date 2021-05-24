/*************************************************************************
	> File Name: 2.test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月27日 星期二 14时37分26秒
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
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {

    int pid;
    if ((pid = fork() < 0)) {
        perror("fork");
        exit(1);
    }
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("child hello \n");
    } else {

    }

    return 0;
}
