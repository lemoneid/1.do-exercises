/*************************************************************************
	> File Name: temp.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 15时04分26秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <inttypes.h>
using namespace std;

int main() {
    char str[10] = {0};
    int n;
    while (~scanf("%d", &n)) {
        sprintf(str, "%x", n);
        printf("%s has %lu digits\n", str, strlen(str));
    }
    return 0;
}
