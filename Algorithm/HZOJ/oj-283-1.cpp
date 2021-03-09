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
char s[MAX_N + 5];

struct Node {
    int flag;
    Node *next[BASE];
};

int root = 1, __cnt = 1;
Node *getNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

int insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - '0';
        if (!p->next[ind]) p->next[ind] = getNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return 1;
}

int query(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - '0';
        if (!p->next[ind]) return 0;
        if (p->next[ind]->flag == 1) return 1;
        p = p->next[ind];
    }
    return 1;
}

void clear(Node *root) {
    if (!root) return;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    Node *root = getNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if (ans) continue;
        ans = query(root, s);
        insert(root, s);
    }
    printf("%s", !ans ? "YES" : "NO");
    return 0;
}
