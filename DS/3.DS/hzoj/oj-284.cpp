/*************************************************************************
	> File Name: oj-284.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 23时13分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define MAX_N 10000
struct Data {
    int p, d;
} data[MAX_N + 5];

set<pair<int, int> > s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i].p >> data[i].d;
    }
    sort(data, data + n, [](const Data &a, const Data &b) {
        if (a.d - b.d) return a.d < b.d;
        return a.p > b.p;
    });
    for (int i = 0; i < n; ++i) {
        if (s.size() < data[i].d) {
            s.insert({data[i].p, i});
        } else {
            if (data[i].p > s.begin()->first) {
                s.erase(s.begin());
                s.insert({data[i].p, i});
            }
        }
    }
    int ans = 0;
    for (auto cur : s) {
        ans += cur.first;
    }
    cout << ans << endl;
    return 0;
}
