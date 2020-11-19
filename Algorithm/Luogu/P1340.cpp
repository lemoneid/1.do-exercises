/*************************************************************************
	> File Name: P1340.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 18时46分46秒
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
#define MAX_N 200

struct Edge {
    int u, v, w, mtime;
};

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int xx = get(x), yy = get(y);
        if (xx == yy) return ;
        fa[xx] = yy;
        return ;
    }
};

Edge e[6005];
UnionSet uset;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].mtime = i;
    }
    sort(e, e + m, [](const Edge &a, const Edge &b){return a.w < b.w;});
    for (int i = 0; i < m; ++i) {
        int already = 1, ans = 0;
        uset.init(n);
        for (int j = 0; j < m; ++j) {
            if (e[j].mtime > i) continue;
            int fu = uset.get(e[j].u), fv = uset.get(e[j].v);
            if (fu == fv) continue;
            uset.merge(fu, fv);
            ans += e[j].w;
            already++;
            if (already == n) break;
        }
        if (already == n) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
