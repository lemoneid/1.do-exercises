/*************************************************************************
	> File Name: cd-17.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月24日 星期四 22时15分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 5000

const int mod = 10e+7;

int dp[MAXN];
int n, m, k, p;
int main() {
    cin >> n >> m >> k >> p;
    dp[m] = 1;
    for (int i = 0; i < k; ++i) {
        int leftup = dp[1];
        for (int j = 1; j <= n; ++j) {
            int tmp = dp[j];
            if (j == 1) {
                dp[j] = dp[j + 1] % mod;
            } else if (j == n) {
                dp[j] = leftup % mod;
            } else {
                dp[j] = leftup + dp[j + 1];
            }
            leftup = tmp;
        }
    }

    cout << dp[p] << endl;

    return 0;
}
