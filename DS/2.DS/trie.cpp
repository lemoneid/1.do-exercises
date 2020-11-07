/*************************************************************************
	> File Name: trie.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月05日 星期四 19时49分21秒
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
#define MAX 26
#define BASECHAR 'a'

struct Node {
    int flag;
    struct Node *next[MAX];
};

struct DATrie {
    int *base, *check;
    int root, size;
};

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASECHAR;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

int query(Node *root, char *s) {
    Node *p = root;
    for (int i = 0; s[i]; ++i) {
        int ind = s[i] - BASECHAR;
        p = p->next[ind];
        if (p == NULL) return 0;
    }
    return p->flag == 1;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < MAX; ++i) {
        buff[k] = BASECHAR + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < MAX; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

DATrie *getDATrie(int n) {
    DATrie *tree = (DATrie *)calloc(sizeof(DATrie), 1);
    tree->root = 1;
    tree->size = n;
    tree->base = (int *)calloc(sizeof(int), n);
    tree->check = (int *)calloc(sizeof(int), n);
    tree->check[tree->root] = 1;
    return tree;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 0, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < MAX; ++i) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < MAX; ++i) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < MAX; ++i) {
        if (root->next[i] == NULL) continue;
        int tmp = buildDATrie(base + i, root->next[i], tree);
        if (tmp > ans) ans = tmp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int queryDATrie(DATrie *tree, const char *s) {
    int p = tree->root;
    for (int i = 0; s[i]; ++i) {
        int ind = s[i] - BASECHAR;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}

void outputDA(DATrie *tree, int ind, int k, char *buff) {
    if (tree->check[ind] < 0) {
        printf("%s\n", buff);
    } 
    for (int i = 0; i < MAX; ++i) {
        int child = tree->base[ind] + i;
        buff[k] = i + BASECHAR;
        buff[k + 1] = '\0';
        if (abs(tree->check[child]) == ind) outputDA(tree, child, k + 1, buff);
    }
    return ;
}

void clearDA(DATrie *tree) {
    if (tree == NULL) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int main() {
    int n, cnt1 = 1, cnt2;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);
        cnt1 += insert(root, str);
    }
    output(root, 0, str);
    DATrie *tree = getDATrie(cnt1 * MAX + 5);
    cnt2 = buildDATrie(tree->root, root, tree) + 1;
    int mem1 = cnt1 * sizeof(Node), mem2 = cnt2 * sizeof(int) * 2 + sizeof(int) * 2;
    printf("Trie memory : %d Bytes\n", mem1);
    printf("Double Array Trie memory : %d Bytes\n", mem2);
    printf("memory rate : %.4lf%%\n", 1.0 * mem2 / mem1 * 100);
    //outputDA(tree, tree->root, 0, str);
    while (~scanf("%s", str)) {
        printf("search %s, result = %s\n", str, queryDATrie(tree, str) ? "YES" : "NO");
    }
    clearDA(tree);
    clear(root);
    return 0;
}
