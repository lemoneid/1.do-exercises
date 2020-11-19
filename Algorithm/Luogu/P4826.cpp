/*************************************************************************
	> File Name: P4826.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 20时10分36秒
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
#define MAX_N 2000
struct Edge {
    int u, v, w;
};

struct UnionSet {
    int fa[MAX_N + 5];
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

struct Edge e[2000005];
int n, mcnt, num[MAX_N + 5];
long long ans;
UnionSet uset;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        for (int j = 1; j < i; ++j) {
            e[mcnt].u = i;
            e[mcnt].v = j;
            e[mcnt++].w = num[i] ^ num[j];
        }
    }
    uset.init(n);
    sort(e, e + mcnt, [](const Edge &a, const Edge &b){ return a.w > b.w; });
    int already = 1;
    for (int i = 0; i < mcnt; ++i) {
        int fu = uset.get(e[i].u), fv = uset.get(e[i].v);
        if (fu != fv) {
            ans += e[i].w;
            already++;
            uset.merge(fu, fv);
            if (already == n) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
