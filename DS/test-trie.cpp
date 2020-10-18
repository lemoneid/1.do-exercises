/*************************************************************************
	> File Name: test-trie.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月18日 星期日 13时55分59秒
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
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        p = p->next[str[i] - BEGIN_LETTER];
        if (!p) return 0;
    }
    return p->flag;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    if (root->flag == 1) {
        printf("%s\n", buff);
        return ;
    } 
    for (int i = 0; i < BASE; ++i) {
        buff[k] = i + BEGIN_LETTER;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}


int main() {
    int n;
    char str[1000];
    Node *root = getNewNode();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        insert(root, str);
    }
    output(root, 0, str);
    while (cin >> str) {
       printf("%s query result = %d\n", str, query(root, str)); 
    }
    return 0;
}
