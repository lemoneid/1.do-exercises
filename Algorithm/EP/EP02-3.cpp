/*************************************************************************
	> File Name: EP02-3.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 19时05分18秒
 ************************************************************************/

#include<cstdio>
#define max_m 4000000

int fib[3] = {1, 1, 2};

int main() {
    int n = 2, sum = 2;
    while(fib[(n - 1) % 3] + fib[(n - 2) % 3] < max_m) {
        n++;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if(fib[n % 3] & 1) continue;
        sum += fib[n % 3];
    }
    printf("%d\n", sum);
    return 0;
}
