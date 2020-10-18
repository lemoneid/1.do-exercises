/*************************************************************************
	> File Name: 23.quick_find.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月17日 星期六 22时03分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->color = (int *)malloc(sizeof(int) * n + 1);
    u->n = n;
    for (int i = 1; i <= n; ++i) {
        u->color[i] = i;
    }
    return u;
}

int find(UnionSet *u, int x) {
    return u->color[x];
}

int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    int color_a = u->color[a];
    for (int i = 1; i <= u->n; ++i) {
        if (u->color[i] - color_a) continue;
        u->color[i] = u->color[b];
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1 : merge(u, b, c); break;
            case 2 : printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");
        }
    }
    clear(u);
    return 0;
}
