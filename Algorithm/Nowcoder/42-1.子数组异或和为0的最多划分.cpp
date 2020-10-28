/*************************************************************************
	> File Name: 42.子数组异或和为0的最多划分.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 13时23分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 1000000

int arr[MAX_N + 5];
int dp[MAX_N + 5];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int eor = 0;
    map <int, int> mmap;
    dp[0] = arr[0] == 0 ? 1 : 0;
    mmap[0] = -1;
    for (int i = 0; i < n; ++i) {
        eor ^= arr[i];
        if (mmap.count(eor)) {
            int idx = mmap[eor];
            dp[i] = (idx == -1 ? 1 : (dp[idx] + 1));
        }
        dp[i] = max(dp[i], dp[i - 1]);
        mmap[eor] = i;
    }
    cout << dp[n - 1] << endl;
    return 0;
}
