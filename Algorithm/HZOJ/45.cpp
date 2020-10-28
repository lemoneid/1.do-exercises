/*************************************************************************
	> File Name: 45.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 11时28分59秒
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
#include <string>
using namespace std;
#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5];
string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] - s2[j - 1]) continue;
            dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
