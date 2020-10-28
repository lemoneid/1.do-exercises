/*************************************************************************
	> File Name: EP48.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月08日 星期一 15时09分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 10000000000;
const long long DIGS = 100000;

long long Multi(long long x, long long y) {
    long long a, b, c, d, ans = 0;
    a = x / DIGS; b = x % DIGS;
    c = y / DIGS; d = y % DIGS;
    ans = (ans + ((a * d % MOD * DIGS)) % MOD) % MOD;
    ans = (ans + ((b * c % MOD * DIGS)) % MOD) % MOD;
    ans = (ans + (b * d % MOD)) % MOD;
    return ans;
}

long long quick_pow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = Multi(ans, a);
        }
        a = Multi(a, a);
        b = b >> 1;
    }
    return ans;
}

int main() {
    long long ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (i % 10 == 0) continue;
        ans += quick_pow(i, i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
