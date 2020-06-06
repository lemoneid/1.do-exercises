/*************************************************************************
	> File Name: EP28-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月02日 星期二 18时55分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max_n 28123

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void  init() {
    for (int i = 2; i < max_n; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1); 
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = prime[j] * prime[j];
            }
        }
    }
    memset(cnt, 0, sizeof(cnt));
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < max_n; ++i) {
        if (f[i] <= 2 * i) continue;
        f[++f[0]] = i;
        prime[i] = 1;
        
    }
}

int main() {
    init();
    long long sum = 1;
    int flag = 1;
    for (int i = 2; i <= max_n; ++i) {
        flag = 1;
        for (int j = 1; flag && f[j] < i; j++) {
            flag = !prime[i - f[j]];
        }
        if (flag) sum += i;
    }
    cout << sum << endl; 
    return 0;
}
