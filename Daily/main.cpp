/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 18时18分48秒
 ************************************************************************/

#include  <cstdio>
#include  <cstdlib>
#include  <inttypes.h>
#include  <stdarg.h>

int max_int(int n, ...) {
    int ans = INT32_MIN, temp;
    va_list arg;
    va_start(arg, n);
    while (n--) {
        temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 8, 4));
    printf("%d\n", max_int(2, 1, 8));
    printf("%d\n", max_int(4, 1, 5, 4, 8, 111));
    return 0;
}
