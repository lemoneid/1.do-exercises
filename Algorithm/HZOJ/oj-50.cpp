/*************************************************************************
	> File Name: oj-50.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 18时44分59秒
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
#define MAX_N 32
#define MAX_M 655536
long long dp[MAX_N + 5][MAX_M + 5];

int main() {
    long long n, m;
    cin >> n >> m;
    if (n == 1) {
        cout <<  m << endl;
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; dp[i][j - 1] < m; ++j) {
            long long val1;
            if (i - 1 == 1) val1 = j - 1;
            else val1 = dp[i - 1][j - 1];
            dp[i][j] = val1 + dp[i][j - 1] + 1;
        }
    }

    
    int k = 1;
    while (dp[n][k] < m) k++;
    cout << k << endl;
    for (int i = 1; i <= k; ++i) {
        cout << i << " = " << dp[n][i] << endl;
    }

    return 0;
}
