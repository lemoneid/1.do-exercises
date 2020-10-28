/*************************************************************************
	> File Name: EP41-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月06日 星期六 18时33分01秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define max_n 100000000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

long long is_val(int *a, int digit) {
    long long sum = 0; 
    for (int i = 0; i < digit; ++i) {
        sum = sum * 10 + a[i];
    }
    return (is_prime[sum] ? 0 : sum) ;
}

int main() {
    init();
    int a[10] = {0};
    long long ans = 0;
    int n = 7; 
    while (n && !ans) {
        for (int i = 0; i < n; ++i) a[i] = n - i;
        do {
            ans = is_val(a, n);
        }while(!ans && prev_permutation(a, a + n));
        n -= 1;
    }
    cout << ans;
    return 0;
}
