/*************************************************************************
	> File Name: cd-67.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 14时47分41秒
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
#define MAX_N 200000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }

    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = val[bb] + 1;
        return ;
    }
};

UnionSet s;
int res[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    s.init(n);
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        s.merge(i, x);
    }
    for (int i = 0; i < n; ++i) {
        s.get(i);
        res[s.val[i]]++; 
    }
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}

