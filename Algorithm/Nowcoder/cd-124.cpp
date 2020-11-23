/*************************************************************************
	> File Name: cd-124.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 14时25分40秒
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
int dp[MAX_N + 5][MAX_N + 5];

string getPalindrome(string str) {
    if (str.size() < 2) return str;
    string res;
    res.resize(str.size() + dp[0][str.size() - 1]);
    int i = 0, j = str.size() - 1;
    int l = 0, r = res.size() - 1;
    while (i <= j) {
        if (str[i] == str[j]) {
            res[l++] = str[i++];
            res[r--] = str[j--];
        } else if (dp[i][j - 1] < dp[i + 1][j]){
            res[l++] = str[j];
            res[r--] = str[j--];
        } else {
            res[l++] = str[i];
            res[r--] = str[i++];
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    for (int j = 1; j < s.size(); ++j) {
        dp[j - 1][j] = (s[j - 1] == s[j] ? 0 : 1);
        for (int i = j - 2; i  > -1; --i) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i][j-  1], dp[i + 1][j]) + 1;
        }
    }
    string res = getPalindrome(s);
    cout << res << endl;
    return 0;
}
