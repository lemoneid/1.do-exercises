/*************************************************************************
	> File Name: 17.trie.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月26日 星期二 23时55分19秒
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
#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

void insert(Node *root, char *str) {
    if (!root) return ;
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        int idx = code(str[i]);
        if (!p->next[idx]) p->next[idx] = getNewNode();
        p = p->next[idx];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    if (!root) return 0;
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        p = p->next[code(str[i])];
        if (!p) return 0;
    }
    return p->flag;
}

void output(Node *root, int k, char *buff) {
    if (!root) return ;
    if (root->flag == 1) {
        printf("%s\n", buff);
    }
    buff[k + 1] = '\0';
    for (int i = 0; i < BASE; ++i) {
        buff[k] = BASE_LETTER + i;
        output(root->next[i], k + 1, buff);
    }
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
    char str[1000];
    int n;
    Node *root = getNewNode();
    cin >> n;
    while (n--) {
        cin >> str;
        insert(root, str);
    }
    output(root, 0, str);
    while (cin >> str) {
        printf("query %s = %s\n", str, query(root, str) ? "Yes" : "False");
    }
    return 0;
}
