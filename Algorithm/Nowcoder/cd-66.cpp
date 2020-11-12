/*************************************************************************
	> File Name: cd-66.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 14时34分19秒
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
#define MAX_N 1000000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i < n + 5; ++i) fa[i] = i;
    }

    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return ;
        fa[fx] = fy;
        return ;
    }
};

UnionSet s;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    s.init(n);
    for (int i = 0, op, x, y; i < m; ++i) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            printf("%s\n", s.find(x) == s.find(y) ? "Yes" : "No");
        } else {
            s.merge(x, y);
        }
    }

    return 0;
}
