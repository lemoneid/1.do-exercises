/*************************************************************************
	> File Name: cd-81.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 13时48分35秒
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

int a[2][MAX_N + 5];
int n;

int solve() {
    int *arr1 = a[0], *arr2 = a[1];
    int s1, s2, e1, e2, m1, m2, offset;
    s1 = s2 = m1 = m2 = 0;
    e1 = e2 = n - 1;
    while (s1 < e1) {
        m1 = (s1 + e1) >> 1;
        m2 = (s2 + e2) >> 1;
        offset = ((e1 - s1 + 1) & 1) ^ 1;
        if (arr1[m1] > arr2[m2]) {
            e1 = m1;
            s2 = m2 + offset;
        } else if (arr1[m1] < arr2[m2]) {
            e2 = m2;
            s1 = m1 + offset;
        } else {
            return arr1[m1];
        }
    }
    return min(arr1[s1], arr2[s2]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i / n][i % n];
    }
    int ans = solve();
    cout << ans << endl;

    return 0;
}
