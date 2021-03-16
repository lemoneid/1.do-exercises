/*************************************************************************
	> File Name: 12.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 14时17分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAX_N 100000
int prime[MAX_N + 5];
int f[MAX_N + 5]; //因子数
int cnt[MAX_N + 5]; //最小素因子个数
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
}

int main() {
    init();
    int fac = 1, n = 1;
    while (fac <= 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) / 2];
        } else {
            fac = f[n / 2] * f[n + 1];
        }
    }
    cout << (n * (n + 1) / 2);
    return 0;
}
