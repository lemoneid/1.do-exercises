/*************************************************************************
	> File Name: EP02-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月05日 星期二 18时37分19秒
 ************************************************************************/
#include<stdio.h>
#define max_n 44
#define max_m 4000000

int fib[max_n+5];

int main() {
    int n = 2, sum = 0;
    fib[0] = 1;
    fib[1] = 2;
    while(fib[n - 1] + fib[n] < max_m) {
        fib[n] = fib[n - 1] + fib[n - 2];
        n++;
    }
    for (int i = 1; i < n; i += 3) {
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}
