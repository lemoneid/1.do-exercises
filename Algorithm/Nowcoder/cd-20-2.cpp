/*************************************************************************
	> File Name: cd-20.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 11时54分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define MAX_N 500
int arr[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n;
unordered_map<int, int>s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    arr[0] = arr[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = arr[i] * arr[i - 1] * arr[i + 1];
    }
    for (int l = n; l > 0; --l) {
        for (int r = l + 1; r <= n; ++r) {
            int finalL = arr[l - 1] * arr[l] * arr[r + 1] + dp[l + 1][r];
            int finalR = arr[l - 1] * arr[r] * arr[r + 1] + dp[l][r - 1];
            dp[l][r] = max(finalL, finalR);
            for (int i = l + 1; i < r; ++i) {
                dp[l][r] = max(dp[l][r], (arr[l - 1] * arr[i] * arr[r + 1] + dp[l][i - 1] + dp[i + 1][r]));
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
