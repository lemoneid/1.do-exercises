/*************************************************************************
	> File Name: oj-71.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月27日 星期三 22时03分12秒
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
#define MAX_N 10000

struct UnionSet {
    int father[MAX_N + 5], size[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) father[i] = i, size[i] = 1;
    }
    int find(int x) {
        return father[x] = (father[x] == x ? x : find(father[x]));
    }
    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return ;
        if (size[fa] > size[fb]) swap(fa, fb);
        father[fa] = fb;
        size[fb] += size[fa];
        return ;
    }
};

UnionSet u;

int main() {
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &m);
    u.init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            u.merge(b, c);
            continue;
        } 
        printf("%s\n",(u.find(b) == u.find(c) ? "Yes" : "No"));
    }

    return 0;
}
