/*************************************************************************
	> File Name: oj-283.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月18日 星期四 20时55分40秒
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
#define BASE 10
char s[15];

struct Node {
    int flag;
    int next[BASE];
} tree[MAX_N + 5];

int root = 1, __cnt = 1;
inline int getNode() { return ++__cnt; }

int insert(const string str) {
    int p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - '0';
        if (!tree[p].next[ind]) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    return 1;
}

int find(const char *str) {
    int p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - '0';
        if (!tree[p].next[ind]) return 0;
        if (tree[tree[p].next[ind]].flag) return 1;
        p = tree[p].next[ind];
    }
    return 1;
}

int main() {
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (find(s)) ans = 0;
        if (!ans) continue ;
        insert(s);
    }
    printf("%s", ans ? "YES" : "NO");
    return 0;
}
