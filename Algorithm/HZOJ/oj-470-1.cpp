/*************************************************************************
	> File Name: oj-470-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月13日 星期四 21时56分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
char to_10[128];
int num[500005];
int dp[500005];
void init() {
    int x = 0;
    for (int i = '0'; i <= '9'; ++i) {
        to_10[i] = x++;
    }

    for (int i = 'A'; i <= 'Z'; ++i) {
        to_10[i] = x++;
    }
    return ;
}

int main() {
    init();
    int cnt = 0, ans = 0;
    string s;
    while (cin >> s) {
        for (int i = 0; i < 5; ++i) {
            num[cnt] = num[cnt] * 36 + to_10[s[i]];
        }
        if (cnt > 0) {
            num[cnt - 1] -= num[cnt];
        } 
        cnt++;
    }

    ans = abs(num[0]);
    dp[0] = num[0];

    for (int i = 0; i < cnt - 1; ++i) {
        cout << num[i] << endl;
    }
    cout << "-----------" << endl;
    cout <<  cnt - 1 << endl;
    cout << dp[0] << endl;
    
    for (int i = 1; i < cnt - 1; ++i) {
        if (abs(num[i]) < abs(dp[i - 1] + num[i])) {
            dp[i] = num[i];
        } else {
            dp[i] = dp[i -1] + num[i];
        }
        cout << dp[i] << endl;
        ans = min(ans, abs(dp[i]));
    }
    cout << ans << endl;
    return 0;
}

