/*************************************************************************
	> File Name: 9.double_array_trie.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月18日 星期四 15时57分46秒
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
#define MSG_LELVEL 1

#ifdef DEBUG
#define LOG(level,frm, args...) {
    if (level >= MSG_LELVEL) {
        printf(frm, ##args); 
    }
}
#else
#endif


typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DANode {
    int base, check, fail;
} DANode;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(p->next));
    return p;
}

inline int code(char c) { return c - 'a'; }

int insert(Node *root, const char *s) {
    Node *p = root;
    int cnt = 0;
    for (int i = 0; s[i]; ++i) {
        int ind = code(s[i]);
        if (!p->next[ind]) p->next[ind] = getNewNode(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}


void clear_trie(Node *root) {
    if (!root) return;
    for (int i = 0; i < BASE; ++i) {
        clear_trie(root->next[i]);
    }
    free(root);
    return ;
}

int get_base_value(Node *root, DANode *tree, int ind) {
    int base = 1, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE; ++i) {
            if (!root->next[i]) continue;
            if (tree[base + i].check != 0) flag = 0;
        }
    } while (flag == 0);
    return base;
}

int transform_double_array_trie(Node *root, DANode *tree, int ind) {
    if (!root) return 0;
    if (root->flag == 1) tree[ind].check = -tree[ind].check;
    int base = get_base_value(root, tree, ind);
    tree[ind].base = base;
    for (int i = 0; i < BASE; ++i) {
        if (!root->next[i]) continue;
        tree[base + i].check = ind;
    }
    int max_ind = ind;
    for (int i = 0; i < BASE; ++i) {
        int ret = transform_double_array_trie(root->next[i], tree, base + i);
        if (ret > max_ind) max_ind = ret;
    }
    return max_ind;
}
void build_ac_base_double_array_trie(DANode *tree, int max_ind) {
    int *que = (int *)malloc(sizeof(int) * (max_ind + 5));
    int head, tail;
    head = tail = 0;
    tree[1].fail = 0;
    for (int i = 0; i < BASE; ++i) {
        int child_ind = tree[1].base + i;
    }
}


int main() {
    int n, cnt = 1;
    char str[1000] = {0};
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    size_t tree_size = sizeof(DANode) * (cnt * BASE);
    DANode *tree = (DANode *)malloc(tree_size);
    memset(tree, 0, tree_size);
    int max_ind = transform_double_array_trie(root, tree, 1);
    build_ac_base_double_array_trie(tree, max_ind);
    free(tree);


    return 0;
}
