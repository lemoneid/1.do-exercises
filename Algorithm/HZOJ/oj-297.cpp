/*************************************************************************
	> File Name: oj-290.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月05日 星期四 14时09分51秒
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
int arr[MAX_N + 5];
int f1[MAX_N + 5], f2[MAX_N + 5];
int n;

inline int bs(int *f, int x, int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return 1;
}

inline int bs1(int *f, int x, int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= x) l = mid;
        else r = mid - 1;
    }
    return 1;
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int len1 = 0, len2 = 0;
    f1[0] = -1;
    f2[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > f1[len1]) f1[++len1] = arr[i];
        else f1[bs(f1, arr[i], 1, len1)] = arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i] < f2[len2]) f2[++len2] = arr[i];
        else f2[bs1(f2, arr[i], 1, len2)] = arr[i];
    }
    cout << min(len1, len2) << endl;

    return 0;
}
