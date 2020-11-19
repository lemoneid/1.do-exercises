/*************************************************************************
	> File Name: P4047.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 19时30分50秒
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

struct UnionSet {
    int fa[1005];
    void init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int xx = get(x), yy = get(y);
        if (xx == yy) return ;
        fa[xx] = yy;
        return ;
    }
};

struct Edge {
    int u, v;
    double w;
};

int n, k, mcnt;
Edge e[500005];
int point[1005][2];
UnionSet uset;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> point[i][0] >> point[i][1];
        for (int j = 1; j < i; ++j) {
            double xx = point[i][0] - point[j][0], yy = point[i][1] - point[j][1];
            double tmp = sqrt(xx * xx + yy * yy);
            e[mcnt].u = i;
            e[mcnt].v = j;
            e[mcnt++].w = tmp;
        }
    }
    sort(e, e + mcnt, [](const Edge &a, const Edge &b){ return a.w < b.w;});
    int already = 0, flag = 0;
    uset.init(n);
    for (int i = 0; i < mcnt; ++i) {
        int fu = uset.get(e[i].u), fv = uset.get(e[i].v);
        if (fu != fv) {
            if (flag == 1) {
                printf("%.2lf\n", e[i].w);
                break;
            }
            uset.merge(fu, fv);
            already++;
            if (already == n - k) {
                flag = 1;
            }
        }
    }

    return 0;
}
