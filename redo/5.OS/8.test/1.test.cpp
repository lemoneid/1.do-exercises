/*************************************************************************
	> File Name: 1.test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 12时54分39秒
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
#include <unistd.h>
using namespace std;

int main() {
    pid_t pid;

    if (pid = (fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid < 0) {
        printf("pid : %d, getpid : %d\n", pid, getpid());
    } else {
        printf("pid : %d, getpid : %d\n", pid, getpid());
    }

    while (1) {}
    return 0;
}
