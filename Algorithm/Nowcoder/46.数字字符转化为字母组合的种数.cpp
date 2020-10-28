/*************************************************************************
	> File Name: 46.数字字符转化为字母组合的种数.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月26日 星期六 21时36分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define MAX_N 100000
const int mod = 1e9 + 7;
string s;
long long dp[3] = {1, 1, 2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    s = " " + s;
    if (s.size() == 1) {
        cout << 0 << endl;
    }
    dp[0] = 1;
    dp[1] = 1;
    if (s[1] == '0') {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i < s.size(); ++i) {
        int a = i % 3, b = (i + 2) % 3, c = (i + 1) % 3;
        if (s[i - 1] == '0') {
            if (s[i] != '0') {
                dp[a] = dp[b];
            } else {
                cout << 0 << endl;
                return 0;
            }
        } else if (s[i - 1] <= '2') {
            if (s[i] == '0') {
                dp[a] = dp[c];
            } else if (s[i] <= '6' || s[i] == '1') {
                dp[a] = dp[b] + dp[c];
                dp[a] %= mod;
            } else {
                dp[a] = dp[b];
            } 
        } else {
            if (s[i] == '0') {
                cout << 0 << endl;
                return 0;
            } else {
                dp[a] = dp[b];
            }
        }
        dp[a] %= mod;
    } 
    cout << dp[(s.size() - 1 + 3) % 3]  % mod << endl;
    return 0;
}
