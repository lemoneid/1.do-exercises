/*************************************************************************
	> File Name: cd-135.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 18时18分18秒
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
#define INF 0x3f3f3f3f

bool judge[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5], len;
string s;

int main() {
    cin >> s;
    len = s.size();
    dp[len] = -1;
    for (int i = len - 1; i >= 0; i--) {
        dp[i] = INF;
        for (int j = i;  j < len; ++j) {
            if (s[i] == s[j] && (j - i < 2 || judge[i + 1][j - 1])) {
                dp[i] = min(dp[i], dp[j + 1] + 1);
                judge[i][j] = true;
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}
