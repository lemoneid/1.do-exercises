/*************************************************************************
	> File Name: 31.最长公共子序列.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月25日 星期五 20时49分07秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 5000

int dp[MAXN + 5][MAXN + 5];
char ans[MAXN + 5];
string s1, s2;
/*
 for (int i = 1; i < len1; ++i) {
        int leftup = dp[0];
        for (int j = 1; j < len2; ++j) {
            int temp = dp[j];
            dp[j] = max(dp[j - 1], dp[j]);
            if (s1[i] == s2[j]) {
                dp[j] = leftup + 1;
            }
            leftup = temp;
        }
    }
*/

int main() {
    cin >> s1 >> s2;
    dp[0][0] = s1.at(0) == s1.at(0) ? 1 : 0;
    for (int i = 1; i < s1.length(); ++i) {
        dp[i][0] = max(dp[i - 1][0], s1.at(i) == s2.at(0) ? 1 : 0);
    }
    for (int i = 1; i < s2.length(); ++i) {
        dp[0][i] = max(dp[0][i - 1], s1.at(0) == s2.at(i) ? 1 : 0);
    }
    
    for (int i = 1; i < s1.length(); ++i) {
        for (int j = 1; j < s2.length(); ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1.at(i) == s2.at(j)) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    int idx = dp[s1.length() - 1][s2.length() - 1];
    int x = s1.length() - 1, y = s2.length() - 1;
    while (1) {
        if (x > 0 && dp[x][y] == dp[x - 1][y]) {
            --x;
        } else if (dp[x][y] == dp[x][y - 1]) {
            --y;
        } else {
            ans[idx--] = s1.at(x);
            --x;
            --y;
            if (idx == 0) break;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
