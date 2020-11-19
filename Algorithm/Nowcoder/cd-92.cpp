/*************************************************************************
	> File Name: cd-92.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 21时10分40秒
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
int arr[MAX_N + 5], dp[MAX_N + 5];
int n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    dp[n - 1] = 0;
    dp[n - 2] = 1;
    for (int i = n - 3; i >= 0; --i) {
        dp[i] = dp[i + 1] + 1;
        for (int j = i + 2; j <= i + arr[i]  && j < n; ++j) {
            dp[i] = min(dp[j] + 1, dp[i]);
        }
    } 
    cout << dp[0] << endl;
    return 0;
}
