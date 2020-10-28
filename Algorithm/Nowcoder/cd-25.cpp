/*************************************************************************
	> File Name: cd-25.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 16 Sep 2020 09:26:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5], dp[MAX_N + 5], val[MAX_N + 5], ans[MAX_N + 5];

int main() {
    int n, len = 1, end = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    val[0] = arr[0];
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int id = lower_bound(val, val + len, arr[i]) - val;
        if (id == len) {
            val[len++] = arr[i];
            dp[i] = len; 
            end = i;
        } else {
            val[id] = arr[i];
            dp[i] = id + 1;
            if (dp[i] == len) end = i;
        }
    }
    int l = len;
    ans[--l] = arr[end];
    for (int i = 0; i < n; ++i) {
        cout << "num = " << arr[i] << "; step = " << dp[i] << endl;
    }
    for (int i = end; i >= 0; --i) {
        //if (arr[i] < arr[end] && dp[i] == dp[end] - 1) {
        if (dp[i] == dp[end] - 1) {
            ans[--l] = arr[i];
            end = i;
        }
    }
    for (int i = 0; i < len; ++i) {
        i && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
