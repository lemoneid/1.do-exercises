/*************************************************************************
	> File Name: P2504-聪明的猴子.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 15时38分38秒
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
const int MAX_M = 500;
const int MAX_N = 1000;

struct Edge {
    int u, v, next;
    double w;
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
};

int n, m, cnt, alreday;
double maxEdge;
Edge e[MAX_N * MAX_N + 5];
int head[MAX_N + 5], monkey[MAX_M + 5], tree[MAX_N + 5][2];
UnionSet uset;

void init() {
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, double w) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
    return ;
}

int main() {
    init();
    cin >> m;
    for (int i = 0; i < m; i++) cin >> monkey[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tree[i][0] >> tree[i][1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double x = fabs(tree[i][0] - tree[j][0]);
            double y = fabs(tree[i][1] - tree[j][1]);
            addEdge(i, j, sqrt(x * x + y * y));
        }
    }
    sort(e, e + cnt, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    }); 

    uset.init(n);
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v;
        if (uset.get(u) == uset.get(v)) continue;
        uset.merge(u, v);
        alreday++;
        maxEdge = max(maxEdge, e[i].w);
        if (alreday == n) break;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (monkey[i] * 1.0 >= maxEdge) ans++;
    }
    cout << ans << endl;
    return 0;
}
