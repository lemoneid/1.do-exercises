/*************************************************************************
	> File Name: P1340-兽径管理.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 16时14分24秒
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
const int MAX_N = 200;
const int MAX_M = 6000;

struct Edge {
    int u, v, w, t;
};

struct UnionSet {
    vector<int> fa;
    void init(int n) {
        fa.resize(n + 1);
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
} uset;

Edge e[MAX_M + 5];
int n, m, alreaday;
int mask[MAX_M + 5];

int prime(int time) {
    uset.init(n);
    memset(mask, false, sizeof(mask));
    int alreaday = 1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (e[i].t > time)  continue;
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (uset.get(u) == uset.get(v)) continue;
        mask[e[i].t] = true;
        uset.merge(u, v);
        alreaday++;
        ans += w;
        if (alreaday == n)  break;
    }
    return alreaday == n ? ans : -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].t = i;
    }

    sort(e, e + m, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    int last = prime(m - 1); 
    vector<int> ans(m);
    ans[m - 1] = last;
    for (int i = m - 2; i >= 0; i--) {
        if (last == -1) {
            ans[i] = -1;
            continue;
        }
        if (mask[i + 1] == true) {
            last = prime(i);
        }
        ans[i] = last;
    }

    for (int i = 0; i < m; i++)  {
        cout << ans[i] << endl;
    }
    return 0;
}
