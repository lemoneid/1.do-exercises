/*************************************************************************
	> File Name: 16.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月18日 星期六 16时14分36秒
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
    int n, m;
    cin >> m >> n;
    m /= 10;
    vector<vector<int>> price(n + 1,vector<int>(3, 0));
    vector<vector<int>> value(n + 1,vector<int>(3, 0));
    for (int i = 1, v, p, q; i <= n; i++) {
        cin >> v >> p >> q;
        v /= 10;
        if (q == 0) {
            price[i][0] = v;
            value[i][0] = v * p;
        } else {
            if (price[q][1] == 0) {
                price[q][1] = v;
                value[q][1] = v * p;
            } else {
                price[q][2] = v;
                value[q][2] = v * p;
            }
        }
    }
#ifdef _D
    for (int i = 1; i <= n; i++) {
        cout << "----- " << i << " ----" << endl;
        for (int j = 0; j < 3; j++) {
            cout << price[i][j] << endl;
        }
    }
#endif

    
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= price[i][0]; j--) {
            int p = price[i][0], v = value[i][0];
            if (j >= p) {
                dp[j] = max(dp[j], dp[j - p] + v);
            }
            p = price[i][0] + price[i][1], v = value[i][0] + value[i][1];
            if (j >= p) {
                dp[j] = max(dp[j], dp[j - p] + v);
            }
            p = price[i][0] + price[i][2], v = value[i][0] + value[i][2];
            if (j >= p) {
                dp[j] = max(dp[j], dp[j - p] + v);
            }
            p = price[i][0] + price[i][1] + price[i][2], v = value[i][0] + value[i][1] + value[i][2];
            if (j >= p) {
                dp[j] = max(dp[j], dp[j - p] + v);
            }
        }
        cout << dp[m] << endl;
    }
    cout << dp[m] * 10 << endl;    
    return 0;
}

