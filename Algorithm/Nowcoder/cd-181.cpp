/*************************************************************************
	> File Name: cd-181.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 14时48分19秒
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
int dp[MAX_N + 5] = {1, 0};
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
