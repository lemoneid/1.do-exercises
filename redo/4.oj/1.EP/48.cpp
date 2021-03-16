/*************************************************************************
	> File Name: EP41.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 20时03分00秒
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

const long long mod = 10000000000LL;

long long multi(long long a, long long b) {
    if (a < b) swap(a, b);
    long long ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return ans % mod;
}

long long quick_pow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = multi(ans, a);
        a = multi(a, a);
        b >>= 1;
    }
    return ans % mod;
}

int main() {
    long long ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % 10 == 0) continue;
        ans += quick_pow(i, i);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
