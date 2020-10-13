/*************************************************************************
	> File Name: 243.秦腾与教学评估.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月12日 星期一 21时36分32秒
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
#define MAX_N  200000

struct Node {
    long long s, e, d;
} data[MAX_N + 5];

long long count(long long n, long long pos) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        if (data[i].s > pos) continue;
        if (data[i].e <= pos) {
            sum += (data[i].e - data[i].s) / data[i].d + 1;
            continue;
        }
        sum += (pos - data[i].s) / data[i].d + 1;
    }
    return sum;
}

long long check(long long n, long long pos) {
   return count(n, pos) % 2; 
}

long long bs(long long l, long long r, long long n) {
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    if (check(n, mid)) return bs(l, mid, n);
    else bs(mid + 1, r, n);
}

long long calc(long long n) {
    long long l, r, mid;
    for (long long i = 0; i < n; ++i) {
        cin >> data[i].s >> data[i].e >> data[i].d;
        if (i == 0) l = data[i].s, r = data[i].e;
        l = min(l, data[i].s);
        r = max(r, data[i].e);
    }
    long long pos = bs(l, r, n);
    long long cnt = count(n, pos) - count(n, pos - 1);
    if (cnt & 1) {
        cout << pos << " " << cnt << endl;
    } else {
        cout << "Poor QIN Teng:(" << endl;
    }
    return 0;
}


int main() {
    long long t, n;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        cin >> n;
        calc(n);
    }
    return 0;
}
