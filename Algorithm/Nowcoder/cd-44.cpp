/*************************************************************************
	> File Name: cd-44.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 21时02分49秒
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
#define MAX_N 5000
string s1, s2, aim;
bool dp[MAX_N + 5][MAX_N + 5];

bool calc(string s1, string s2, string aim) {
    if (s1.size() + s2.size() != aim.size() + 1) return false;
    dp[0][0] = true;
    for (int i = 1; i < s1.size(); ++i) {
        if (s1[i] != aim[i]) break;
        dp[i][0] = true;  
    }
    for (int i = 1; i < s2.size(); ++i) {
        if (s2[i] != aim[i]) break;
        dp[0][i] = true;
    }
    for (int i = 1; i < s1.size(); ++i) {
        for (int j = 1; j < s2.size(); ++j) {
            if (dp[i - 1][j] && s1[i] == aim[i + j]) {
                dp[i][j] = true;
            }
            if (dp[i][j - 1] && s2[j] == aim[i + j]) {
                dp[i][j] = true;
            }
        }
    }
    return dp[s1.size() - 1][s2.size() - 1];
}

int main() {
    cin >> s1 >> s2 >> aim;
    bool ans = calc(" " + s1, " " + s2, " " + aim);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
