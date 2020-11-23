/*************************************************************************
	> File Name: cd-181-4.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 16时43分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MOD 1000000007
#define MAX_N 10000

long long inv[MAX_N + 5];
long long ans;

void init_inv(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    return ;
}

int main() {
    int n;
    cin >> n;
    init_inv(n + 1);
    ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = ((ans * (4 * i - 2)) % MOD) * inv[i + 1] % MOD;
    }
    cout << ans << endl;
    return 0;
}
