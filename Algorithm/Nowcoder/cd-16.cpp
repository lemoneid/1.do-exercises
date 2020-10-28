/*************************************************************************
	> File Name: cd-16.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月15日 星期二 11时06分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
#define MAX_N 2000

int arr[MAX_N + 5][MAX_N + 5];
int h[MAX_N + 5];
int calc_max(int *h, int len) {
    stack <int> sta;
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        while (!sta.empty() && h[sta.top()] >= h[i]) {
            int j = sta.top();
            sta.pop();
            int k = sta.empty() ? -1 : sta.top();
            ans = max(ans, (i - k - 1) * h[j]);
        }
        sta.push(i);
    }
    while (!sta.empty()) {
        int j = sta.top();
        sta.pop();
        int k = sta.empty() ? -1 : sta.top();
        ans = max(ans, (len - k - 1) * h[j]); 
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    int ans  = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            h[j] = arr[i][j] == 0 ? 0 : h[j] + 1;
        }
        ans = max(ans, calc_max(h, m));
    }
    cout << ans << endl;
    return 0;
}
