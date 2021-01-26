/*************************************************************************
	> File Name: oj-243.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月25日 星期一 21时44分38秒
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
#define MAX_N 200000

struct Data {
    long long s, e, d;
} arr[MAX_N + 5];

long long count(long long n, long long pos) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        if (arr[i].s > pos) continue;
        if (arr[i].e <= pos) sum += (arr[i].e - arr[i].s) / arr[i].d + 1;
        else sum += (pos - arr[i].s) / arr[i].d + 1;
    }
    return sum;
}

long long check(long long n, long long pos) {
    return count(n, pos) & 1;
}

long long bs(long long l, long long r ,long long n) {
    while (l < r) {
        long long mid = (l + r) >> 1;
        if (check(n, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    long long n, l, r;
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(l, arr[i].s);
        r = max(r, arr[i].e);
    }
    long long pos = bs(l, r, n);
    long long cnt = count(n, pos) - count(n, pos - 1);
    if (cnt & 1) {
        cout << pos << " " << cnt << endl;
    } else {
        cout << "Poor QIN Teng:(" << endl;
    }
    return ;
}

int main() {
    long long tcase;
    cin >> tcase;
    while (tcase--) solve();

    return 0;
}
