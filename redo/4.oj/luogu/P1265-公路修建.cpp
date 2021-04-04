/*************************************************************************
	> File Name: P1265-公路修建.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 16时03分28秒
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
const int MAX_N = 5000;
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
} union_set;

int cnt,alreaday, n;
double ans;
int head[MAX_N + 5], city[MAX_N + 5][2];
Edge e[MAX_N * MAX_N + 5];

void init() {
    memset(head, -1, sizeof(head));
}
 
inline void addEdge(int u, int v, double w) {
    e[cnt].u = u;
    e[cnt].w = w;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> city[i][0] >> city[i][1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double x = fabs(city[i][0] - city[j][0]);
            double y = fabs(city[i][1] - city[j][1]);
            addEdge(i, j, sqrt(x * x + y * y));
        }
    }
    union_set.init(n);
    sort(e, e + cnt, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v;
        if (union_set.get(u) == union_set.get(v)) continue;
        union_set.merge(u, v);
        alreaday++;
        ans += e[i].w;
        if (alreaday == n) break;
    }
    printf("%.2lf\n", ans);
    return 0;
}
