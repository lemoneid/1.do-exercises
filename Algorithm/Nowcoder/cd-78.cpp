/*************************************************************************
	> File Name: cd-78.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 12时30分12秒
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

int l[MAX_N + 5], r[MAX_N + 5], arr[MAX_N + 5];
int n, ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i], l[i] = r[i] = 1;
    for (int i = 2, j = n - 1; i <= n; ++i, --j) {
        if (arr[i] > arr[i - 1]) {
            l[i] += l[i - 1];
        } else if (arr[i] == arr[i - 1]) {
            l[i] = l[i - 1];
        }
        if (arr[j] > arr[j + 1]) {
            r[j] += r[j + 1];
        } else if (arr[j] == arr[j + 1]) {
            r[j] = r[j + 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += max(l[i], r[i]);
    }
    cout << ans << endl;

    return 0;
}
