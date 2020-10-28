/*************************************************************************
	> File Name: 242.最大平均值.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月12日 星期一 20时59分38秒
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
long long arr[MAX_N + 5];
long long b[MAX_N + 5];
bool check(long long n, long long m, long long val) {
    for (long long i = 1; i <= n; ++i) b[i] = arr[i] - val;
    for (long long i = 1; i <= n; ++i) b[i] += b[i - 1];
    long long pre = 0;
    for (long long i = m; i <= n; ++i) {
        pre = min(pre, b[i - m]);
        if (b[i] - pre >= 0) return true;
    }
    return false;
}

long long bs(long long l, long long r, long long n, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(n, m, mid)) return bs(mid, r, n, m);
    return bs(l, mid - 1, n, m);

}

int main() {
    long long n, m, s, t;
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 1) s = t = arr[i];
        s = min(s, arr[i]);
        t = max(t, arr[i]);
    }
    cout << bs(s, t, n, m) << endl;
    return 0;
}
