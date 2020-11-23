/*************************************************************************
	> File Name: cd-127.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 11时05分44秒
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
#define MAX_N 100000
int dp[MAX_N], ans;
string s;

int main() {
    cin >> s;
    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int pre = 0, res = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            pre = i - dp[i - 1] - 1;
            if (pre >= 0 && s[pre] == '(') {
                dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0 );
            }
        }
        ans = max(ans, dp[i]);        
    }
    cout << ans << endl;
    return 0;
}
