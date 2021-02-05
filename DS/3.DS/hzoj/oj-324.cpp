/*************************************************************************
	> File Name: oj-324.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月29日 星期五 23时18分40秒
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
#define MAX_N 500000

struct UnionSet {
    int fa[MAX_N + 5], size[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            size[i] = 1;
            val[i] = 0;
        }
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
        val[aa] = size[bb];
        size[bb] += size[aa];
    }
};

UnionSet u;

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    u.init(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%s%d%d", str, &a, &b);
        switch (str[0]) {
            case 'M' : u.merge(a, b); break;
            case 'C' : {
                if (u.get(a) - u.get(b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[a] - u.val[b]) -1);
                }
            } break;
        }
    }

    return 0;
}
