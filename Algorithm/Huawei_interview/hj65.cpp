/*************************************************************************
	> File Name: hj65.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月28日 星期二 17时56分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1.size() > s2.size()) swap(s1, s2);
        int row = s1.size(), col = s2.size();
        vector<vector<int>> dp(row + 5, vector<int>(col + 5, 0));
        int max_len = 0, pos = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    pos = i;
                }
            }
        }
        cout << s1.substr(pos - max_len, max_len) << endl;
    }
    return 0;
}
