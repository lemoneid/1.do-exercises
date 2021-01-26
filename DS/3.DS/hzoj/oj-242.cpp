/*************************************************************************
	> File Name: oj-242.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月25日 星期一 20时53分59秒
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
#define MAX_N 100000
int arr[MAX_N + 5];
long long b[MAX_N + 5];

bool check(int n, int m, int val) {
    for (int i = 1; i <= n; ++i) b[i] = arr[i] - val;
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
    long long pre = 0;
    for (int i = m; i <= n; ++i) {
        pre = min(pre, b[ i - m ]);
        if (b[i] - pre >= 0) return true;
    }
    return false;
}


int main() {
    int n, m, s, t;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i]; 
        arr[i] *= 1000;
        if (i == 1) s = t = arr[i];
        s = min(s, arr[i]);
        t = max(t, arr[i]);
    }
    while (s < t) {
        int mid = (s + t + 1) >> 1;
        if (check(n, m, mid)) s = mid;
        else t = mid - 1;
    }
    cout << s << endl;
    return 0;
}
