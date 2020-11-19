/*************************************************************************
	> File Name: cd-82.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 14时31分22秒
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
int a1[MAX_N + 5], a2[MAX_N + 5];

int getUpMedian(int *arr1, int s1, int e1, int *arr2, int s2, int e2) {
    int m1, m2, offset;
    if (e1 - s1 != e2 - s2) return -1;
    while (s1 < e1) {
        m1 = (e1 + s1) >> 1;
        m2 = (e2 + s2) >> 1;
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

int getKth(int *arr1, int *arr2, int kth, int l, int s) {
    if (kth < 1 || kth > (l + s)) return -1; 
    int *longs = NULL, *shorts = NULL;
        longs = arr1;
        shorts = arr2;
    if (l < s) {
        longs = arr2;
        shorts = arr1;
        swap(l, s);
    }
    if (kth <= s) {
        return getUpMedian(longs, 0, kth - 1, shorts, 0, kth - 1);
    }
    if (kth > l) {
        if (shorts[kth - l - 1] >= longs[l - 1]) {
            return shorts[kth - l - 1];
        }
        if (longs[kth - s - 1] >= shorts[s - 1]) {
            return longs[kth - s - 1];
        }
        return getUpMedian(longs, kth - s, l - 1, shorts, kth - l, s - 1);
    }
    if (longs[kth - s - 1] >= shorts[s - 1]) {
        return longs[kth - s - 1];
    }
    return getUpMedian(longs, kth - s, kth - 1, shorts, 0, s - 1);

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int l, s, kth;
    cin >> l >> s >> kth;
    for (int i = 0; i < l; ++i) cin >> a1[i];
    for (int i = 0; i < s; ++i) cin >> a2[i];
    int ans = getKth(a1, a2, kth, l, s);
    cout << ans << endl;

    return 0;
}
