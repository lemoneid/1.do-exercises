/*************************************************************************
	> File Name: oj-323.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月29日 星期五 21时35分48秒
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

struct UnionSet {
    int father[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) father[i] = i;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        father[get(a)] = get(b);
    }
};

struct Data {
    int p, d;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.p > b.p;
}

UnionSet u;

int solve() {
    int n;
    if (!(cin >> n)) return 0;
    u.init(MAX_N);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int day = u.get(arr[i].d);
        if (day == 0) continue;
        ans += arr[i].p;
        u.merge(day, day - 1);
    }
    cout << ans << endl;
    return 1;
}

int main() {
    while (solve());
    return 0;
}
