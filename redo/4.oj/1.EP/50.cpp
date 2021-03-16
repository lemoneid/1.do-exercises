/*************************************************************************
	> File Name: 50.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 21时28分29秒
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
#define MAX_N 1000000
int prime[MAX_N + 5];
int check[MAX_N + 5];
long long sum[MAX_N + 5];
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!check[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    sum[0] = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum[i] = sum[i - 1] + prime[i];
    }
    return ;
}

int main() {
    init();
    long long cnt = 0, ans = 0;
    for (int i = 0; i < prime[0]; i++) {
        for (int j = i + 1; j <= prime[0]; j++) {
            long long x = sum[j] - sum[i];
            if (x > prime[prime[0]]) break;
            if (check[x] == 0 && j - i > cnt) {
                cnt = j - i;
                ans = x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
