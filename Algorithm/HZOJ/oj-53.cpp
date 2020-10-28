/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月28日 星期四 18时48分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 1000000;
int prime[max_n + 5] ={0};
long long f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

int init() {
    for (int i = 2; i <= max_n; ++i ) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = i * i;
            f[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] * prime[j];
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
                break;
            } else {
                cnt[i * prime[j]] = prime[j] * prime[j];
                f[i * prime[j]] = f[i] * f[prime[j]];
            }
        }
    }
}


int main() {
    init();
    long long num = 0;
    for (int i = 2; i <= max_n;  ++i) {
        if (num < f[i]) num = f[i];
    }
    cout << num << endl;
    return 0;
}
