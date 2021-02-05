/*************************************************************************
	> File Name: oj-323-2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月29日 星期五 22时44分28秒
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
#define MAX_N 10000

struct Data {
    int p, d;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.d < b.d;
}

int solve() {
    set<pair<int, int>> s;
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (s.size() < arr[i].d) {
            s.insert({arr[i].p, i});
        } else if (s.begin()->first < arr[i].p) {
            s.erase(s.begin());
            s.insert({arr[i].p, i});
        }
    }
    int ans = 0;
    for (auto cur : s) {
        ans += cur.first;
    }
    cout << ans << endl;
    return 1;
}

int main() {
    while (solve());
    return 0;
}

