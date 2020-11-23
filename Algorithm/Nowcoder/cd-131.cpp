/*************************************************************************
	> File Name: cd-131.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 17时46分14秒
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
#define MAX_N 100000

int arr[MAX_N + 5], dp[MAX_N + 5];
unordered_map<int, int> mmap;
int n, ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
    for (int i = 1; i <= n; ++i) {
        if (mmap[arr[i] == 0]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = min(dp[i - 1] + 1, i - mmap[arr[i]]);
        }
        ans = max(ans, dp[i]);
        mmap[arr[i]] = i;
    }
    cout << ans << endl;
    return 0;
}
