/*************************************************************************
	> File Name: oj-244.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月25日 星期一 23时34分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAX_N 500

struct Data {
    int x, y;
} arr[MAX_N + 5];
int tmp[MAX_N + 5];

bool check_y(int l, int r, int c, int len) {
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        tmp[cnt++] = arr[i].y;
    }
    sort(tmp, tmp + cnt);
    for (int i = c - 1; i < cnt; ++i) {
        if (tmp[i] - tmp[i - c + 1] < len)  return true;
    }
    return false;
}

bool check(int n, int len, int c) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (arr[i].x - arr[j].x >= len) j++;
        if (arr[i].x - arr[j].x + 1 < c) continue;
        if (check_y(j, i, c, len)) return true;
    }
    return false;
}

bool cmp(const Data &a, const Data &b) {
    return a.x < b.x;
}

int main() {
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n, cmp);
    int l = 1, r = 10000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(n, mid, c)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
