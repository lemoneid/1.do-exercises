/*************************************************************************
	> File Name: EP21.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月26日 星期二 20时51分44秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
#define max_n 10000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!prime[i])  {
            prime[++prime[0]] = i;
            cnt[i] = i * i;
            f[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < max_n; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                cnt[prime[j] * i] = cnt[i] * prime[j];
                f[prime[j] * i] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
                break;
            } else {
                cnt[prime[j] * i] = prime[j] * prime[j];
                f[prime[j] * i] = f[prime[j]] * f[i];
            }
        }
    }
}


int main() {
    init();
    for (int i = 2; i < max_n; ++i ) {
        f[i] -= i;
    }
    long long sum = 0; 
    for (int i = 2; i < max_n; ++i) {
        if (f[i] < max_n && i != f[i] && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}

