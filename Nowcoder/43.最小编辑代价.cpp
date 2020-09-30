/*************************************************************************
	> File Name: 43.最小编辑代价.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 14时13分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 5000
int ic, dc, rc;
string s1, s2;
int dp[MAX_N + 5];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> ic >> dc >> rc;    
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 1; i < s2.size(); ++i) dp[i] = i * ic;
    for (int i = 1; i < s1.size(); ++i) {
        int leftup = dp[0];
        dp[0] += dc;
        for (int j = 1; j < s2.size(); ++j) {
            int tmp  = dp[j];
            dp[j] = min(dp[j] + dc, dp[j - 1] + ic);
            dp[j] = min(dp[j], leftup + rc);
            if (s1[i] == s2[j]) {
                dp[j] = min(dp[j], leftup);
            }
            leftup = tmp;
        }
    }
    /*
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[s2.size() - 1] << endl; 
    return 0;
}
