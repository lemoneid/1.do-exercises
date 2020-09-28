/*************************************************************************
	> File Name: 42-2.子数组异或和为0的最多划分.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 14时06分12秒
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
int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int eor = 0, ans = 0;
    set <int> se;
    for (int i = 0; i < n; ++i) {
        eor ^= arr[i];
        if (eor == 0 || se.count(eor)) {
            eor = 0;
            se.clear();
            ans++;
        } else {
            se.insert(eor);
        }
    }
    cout << ans << endl;
    return 0;
}
