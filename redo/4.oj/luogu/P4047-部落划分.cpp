/*************************************************************************
	> File Name: P4047-部落划分.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月03日 星期六 19时04分40秒
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
const int MAX_N = 1000;

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

struct Edge {
    int u, v;
    double w;
};

int n, k, cnt;
int locate[MAX_N + 5][2];
Edge e[MAX_N * MAX_N + 5];
inline void addEdge(int u, int v, double w) {
    e[cnt].u = u;
    e[cnt].w = w;
    e[cnt].v = v;
    cnt++;
};

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%d%d", &locate[i][0], &locate[i][1]);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double x = fabs(locate[i][0] - locate[j][0]);
            double y = fabs(locate[i][1] - locate[j][1]);
            addEdge(i, j, sqrt(x * x + y * y));
        }
    }
    sort(e, e + cnt, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    uset.init(n);
    int alreaday = 0;
    int flag = 0;
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v;
        if (uset.get(u) == uset.get(v)) continue;
        if (flag) {
            printf("%.2lf\n", e[i].w);
            break;
        }
        uset.merge(u, v);
        alreaday++;
        if (alreaday == n - k) {
            flag = 1;
        }
    }
    return 0;
}
