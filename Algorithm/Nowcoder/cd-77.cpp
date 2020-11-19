/*************************************************************************
	> File Name: cd-77.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月13日 星期五 16时39分05秒
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
int arr[MAX_N + 5];
int l[MAX_N + 5], r[MAX_N + 5];
int n, ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int a = 1, b = 1;
    for (int i = 2, j = n - 1; i <= n; ++i, --j) {
        if (arr[i] > arr[i - 1]) {
            l[i] += a++;
        } else {
            a = 1;
        }
        if (arr[j] > arr[j + 1]) {
            r[i] += b++;
        } else {
            b = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += max(l[i], r[i]);
    }
    ans += n;
    cout << ans << endl;
    return 0;
}
