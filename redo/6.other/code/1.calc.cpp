/*************************************************************************
	> File Name: 1.test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月23日 星期五 14时50分27秒
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
#include <assert.h>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv) {
    int *p = (int *)malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) memory address of p : %p\n", getpid(), p);
    *p = 0;
    while (1) {
        sleep(1);
        *p = *p + 1;
        printf("(%d) p : %d\n", getpid(), *p);
    }

    return 0;
}
