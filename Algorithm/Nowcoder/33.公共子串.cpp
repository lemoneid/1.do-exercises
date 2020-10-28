/*************************************************************************
	> File Name: 33.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月25日 星期五 22时09分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 5000

string s1, s2, ans;
int dp[MAXN + 5];
int x, mmax;
int main() {
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 1; i < s1.size(); ++i) {
        int leftup = 0;
        for (int j = 1; j < s2.size(); ++j) {
            int temp = dp[j];
            dp[j] = 0;
            if (s1.at(i) == s2.at(j)) {
                dp[j] = leftup + 1;
                if (mmax < dp[j]) {
                    x = j;
                    mmax = dp[j];
                }
            }
            leftup = temp; 
        }
    }
    ans.assign(s2, x - mmax + 1, mmax);
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
