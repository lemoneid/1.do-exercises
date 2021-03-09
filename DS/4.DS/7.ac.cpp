/*************************************************************************
	> File Name: 7.ac.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月17日 星期三 11时34分09秒
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

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
    char *str;
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag - 0;
    memset(p->next, 0, sizeof(p->next));
    p->fail = nullptr;
    return p;
}

void insert(Node *root, const char *str) {
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (!root->next[ind]) root->next[ind] = getNewNode();
        root = root->next[ind];
    }
    root->flag = 1;
    root->str = strdup(str);
    return ;
}
    

void build_ac(Node *root) {
    root->fail = nullptr;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        for (int i = 0; i < BASE; ++i) {
            Node *c = p->next[i], *k = p->fail;
            if (!c) continue;
            while (k && !k->next[i]) k = k->fail;
            if (k == nullptr) k = root;
            //+else ?
            if (k->next[i]) k = k->next[i];
            c->fail = k;
            q.push(c);
        }
    }
    return ;
}

void match(Node *root, const char *text) {
    Node *p = root, *q = nullptr;
    for (int i = 0; text[i]; ++i) {
        int ind = text[i] - 'a';
        /*
        while (p && p->next[ind] == nullptr) p = p->fail;
        if (p == nullptr) p = root;
        if (p->next[ind]) p = p->next[ind];
        */
        p = p->next[ind];
        q = p;
        while (q) {
            if (q->flag == 1) cout << "find : %s\n" << endl;
            q = q->fail;
        }
    }
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    int n;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(root, str);
    }
    build_ac(root);
    scanf("%s", str);
    match(root, str);
    return 0;
}
