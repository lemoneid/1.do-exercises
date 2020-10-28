/*************************************************************************
	> File Name: oj-51.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 19时01分33秒
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
#define MAX_N 1000
int n, m;
int mmap[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5][2];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    int ans  = 0;
    for (int i = 1; i <= n; ++i) {
        dp[0][0] = 0;
        for (int j = 1; j <= n; ++j) {
            if (mmap[i][j] == 0) {
                dp[j][0] = 0;
                dp[j][1] = 0;
                continue;
            }
            ans += ++dp[j][1];
            dp[j][0] = dp[j - 1][0] + 1;
            ans += dp[j][0];
        }
    }
    cout << ans << endl;
    return 0;
}
