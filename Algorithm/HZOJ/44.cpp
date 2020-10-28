/*************************************************************************
	> File Name: 44.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 10时58分35秒
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
#define MAX_N 1000000

int dp[MAX_N  + 5];
int ans = 0;

int bs(int *arr, int l, int r, int x) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n, val = 0;
    cin >> n;
    cin >> val;
    dp[++ans] = val;
    for (int i = 2; i <= n; ++i) {
        cin >> val;
        if (val > dp[ans]) dp[++ans] = val;
        else {
            int ind = bs(dp, 1, ans, val);
            dp[ind] = val;
        }
    }
    cout << ans << endl;
    return 0;
}
