/*************************************************************************
	> File Name: 45.龙与地下城游戏问题.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月26日 星期六 16时15分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1000

int mmap[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mmap[i][j];
        }
    }
    dp[n][m] = mmap[n][m] > 0 ? 1 : -mmap[n][m] + 1;
    for (int j = m - 1; j > 0; --j) {
        dp[n][j] = max(1, dp[n][j + 1] - mmap[n][j]);
    }
    for (int i = n - 1; i > 0; --i) {
        dp[i][m] = max(1, dp[i + 1][m] - mmap[i][m]);
        for (int j = m - 1; j > 0; --j) {
            int right = max(1, dp[i][j + 1] - mmap[i][j]);
            int down = max(1, dp[i + 1][j] - mmap[i][j]);
            dp[i][j] = min(right, down);
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
