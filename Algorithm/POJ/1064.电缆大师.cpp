/*************************************************************************
	> File Name: 1064.电缆大师.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年10月04日 星期一 11时37分05秒
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

const double EPS = 1e-8;
vector<double> arr;
int n, k;

bool f(long long x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (long long)(arr[i]) / x;
    }
    return cnt >= k;
}

void solve() {
    arr.resize(n);
    long long l = 0, r = 0, mid;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= 100;
        r = max((long long)(arr[i]), r);
    }
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        if (f(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%.2lf\n", floor((double)(l)/ 100.0));
    return ;
}

int main() {
    while (cin >> n >> k) {
        solve();
    }
    return 0;
}
