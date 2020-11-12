/*************************************************************************
	> File Name: cd-68.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 15时33分46秒
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
#define MAX_N 100
#define MAX_M 10000

bool dp[MAX_M + 5];
int arr[MAX_N + 5];
int n, l, r;
int main() {
    cin >> n;
    cin >> arr[0];
    l = r = arr[0];
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        l = min(l, arr[i]);
        r += arr[i];
    }
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = r; j >= arr[i]; --j) {
            dp[j] = dp[j - arr[i]] ? 1 : dp[j];
        }
    }

    for (int i = l; i <= r; ++i) {
        if(!dp[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << r + 1 << endl;

    return 0;
}
