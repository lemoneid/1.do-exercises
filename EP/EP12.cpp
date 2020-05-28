/*************************************************************************
	> File Name: EP12.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月24日 星期日 18时42分32秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i; 
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < max_n; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                cnt[prime[j] * i] = 1;
                f[prime[j] * i] = f[prime[j]] * f[i];
            }
        }
    }
    return ;
}


int main() {
    init(); 
    int n = 0, fac = 0;
    while(fac <= 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << (n * (n + 1) / 2) << endl;
    return 0;
}
