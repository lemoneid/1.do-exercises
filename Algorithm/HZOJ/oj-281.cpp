/*************************************************************************
	> File Name: oj-281.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月18日 星期四 20时20分23秒
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
#include <queue>
using namespace std;
#define BASE 26
#define MAX_N 1000000

struct Node {
    int flag, fail;
    int next[BASE];
} tree[MAX_N + 5];

char s[MAX_N + 5];
int __cnt = 1, root = 1;
inline int getNode() {return ++__cnt; }

void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - 'a';
        if (!tree[p].next[ind]) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag += 1;
}

void build_ac() {
    queue<int> q;
    q.push(root);
    tree[root].fail = root;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < BASE; ++i) {
            if (!tree[p].next[i]) continue;
            int k = tree[p].fail;
            while (k && !tree[k].next[i]) k = tree[k].fail;
            if (!k) k = root;
            else k = tree[k].fail;
            tree[tree[p].next[i]].fail = k;
            q.push(tree[p].next[i]);
        }
    }
    return ;
}

int query(const char *str) {
    int cnt = 0, p = root;
    for (int i = 0; p && str[i]; ++i) {
        int ind = str[i] - 'a';
        p = tree[p].next[ind];
        cnt += tree[p].flag;
    }
    return cnt;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        insert(s);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}
