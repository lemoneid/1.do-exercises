/*************************************************************************
	> File Name: oj-255.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月26日 星期一 20时56分06秒
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
#define MAX_N 1000

struct Range {
    double x, y;
} arr[MAX_N + 5], point[MAX_N + 5];

int n;
double d;

bool cmp(const Range &a, const Range &b) {
    if (a.y - b.y) return a.y < b.y;
    return a.x > b.x;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> point[i].x >> point[i].y;
        double c = d * d - point[i].y * point[i].y;
        if (c < 0) {
            cout << -1 << endl;
            return 0;
        }
        c = sqrt(c);
        arr[i].x = point[i].x - c;
        arr[i].y = point[i].x + c;
    }
    sort(arr, arr + n, cmp);
    double p = arr[0].y;
    int ans = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i].x <= p) continue;
        p = arr[i].y;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
