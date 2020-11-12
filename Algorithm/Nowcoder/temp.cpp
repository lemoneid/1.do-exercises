/*************************************************************************
	> File Name: temp.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 18时24分39秒
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
#define MAX_N 500
int a[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) dp[i][i] = a[i - 1] * a[i] * a[i + 1];
    for (int i = n - 1; i > 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
            int mul = a[i - 1] * a[j + 1];
            int fl = a[i] * mul + dp[i + 1][j];
            int fr = a[j] * mul + dp[i][j - 1];
            dp[i][j] = max(fl, fr);
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], a[k] * mul + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
    } 
    printf("%d\n", dp[1][n]);
    return 0;
}
