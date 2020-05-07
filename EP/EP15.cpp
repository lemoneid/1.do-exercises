/*************************************************************************
	> File Name: EP15.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 07 May 2020 01:28:00 PM CST
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <inttypes.h>

int main() {
    int64_t ans = 1, m = 20;
    for (int32_t i = 40; i > 20; --i) {
        ans *= i;
        while (ans % m == 0 && m != 1) {
            ans /= m;
            --m;
        } 
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
