/*************************************************************************
	> File Name: 21.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 19时59分10秒
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
#define MAX_N 10000
int prime[MAX_N + 5];
int f[MAX_N + 5];
int cnt[MAX_N + 5];

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1) ; 
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            } else {
                cnt[i * prime[j]] = prime[j] * prime[j];
                f[i * prime[j]] = f[prime[j]] * f[i];
            }
        }
    }
    return ;
}


int main() {
    init();
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        f[i] -= i;
    }
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] < MAX_N) {
            int a = i, b = f[i];
            if (a != b && f[a] == b && f[b] == a) {
                cout << i << endl;
                sum += i;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
