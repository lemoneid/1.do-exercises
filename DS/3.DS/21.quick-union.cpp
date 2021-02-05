/*************************************************************************
	> File Name: 21.quick-union.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月27日 星期三 21时53分05秒
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
typedef struct UnionSet {
    int *father, *count;
    int size;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->count = (int *)malloc(sizeof(int) * n);
    u->size = n;
    for (int i = 0; i < n; ++i) {
        u->father[i] = i;
        u->count[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
} 

void merge(UnionSet *u, int a, int b) {
   int fa = find(u, a), fb = find(u, b); 
    if (fa == fb) return ;
    if (u->count[fa] < u->count[fb]) {
        swap(fa, fb);
    }
    u->father[fb] = fa;
    u->count[fa] += u->count[fb];
    return ;
}

void clear(UnionSet *u) {
    if (!u) return;
    free(u->father);
    free(u->count);
    free(u);
    return ;
}

int main() {
 int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;

}
