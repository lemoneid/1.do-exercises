/*************************************************************************
    > File Name: test.cpp
    > Author: yanzhiwei
    > Mail: 1931248856@qq.com
    > Created Time: 2021年01月21日 星期四 20时46分28秒
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
#define inf 0x3f3f3f

int a[MAX_N + 5];
int l[MAX_N + 5], pre[MAX_N + 5], nxt[MAX_N + 5];
typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n, k;
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = a[i] - a[i - 1];
        pre[i] = i - 1;
        nxt[i] = i + 1 > n ? 0 : i + 1;
        s.insert(PII(l[i], i));
    }
    int sum = 0;
    while (k) {
        int t0 = s.begin()->second, t1 = pre[t0], t2 = nxt[t0];
        if (t1 == 0 || l[t0] != s.begin()->first) {
            s.erase(s.begin());
            continue;
        }
        s.erase(s.begin());
        sum += l[t0];
        k--;
        l[t0] = l[t1] + l[t2] - l[t0];
        l[t1] = l[t2] = inf;
        if (t2 == 0) continue;
        pre[t0] = pre[t1];
        nxt[t0] = nxt[t2];
        nxt[pre[t1]] = t0;
        pre[nxt[t2]] = t0;
        s.insert(PII(l[t0], t0));
    }
    cout << sum << endl;

    return 0;
}
