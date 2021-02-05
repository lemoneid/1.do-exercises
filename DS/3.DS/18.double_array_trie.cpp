/*************************************************************************
	> File Name: 18.double_array_trie.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月27日 星期三 15时45分12秒
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
#include <ctime>
using namespace std;
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *getDATrie(int n) {
    DATrie *tree = (DATrie *)calloc(sizeof(DATrie), 1);
    tree->root = 1;
    tree->size = n;
    tree->base = (int *)calloc(sizeof(int), n);
    tree->check = (int *)calloc(sizeof(int), n);
    tree->check[tree->root] = -1;
    return tree;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, char *s) {
    if (!root) return 0;
    Node *p = root;
    int cnt = 0;
    for (int i = 0; s[i]; ++i) {
        int idx = s[i] - BEGIN_LETTER;
        if (!p->next[idx]) p->next[idx] = getNewNode(), cnt += 1;
        p = p->next[idx];
    }
    p->flag = 1;
    return cnt;
}
//层序确定base


int getBaseEValue(Node *root, DATrie *tree) {
    int base = 0, flag = 1;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; ++i) {
            if (!root->next[i]) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

//递归确定base
int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseEValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; ++i) {
        if (!root->next[i]) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; ++i) {
        if (!root->next[i]) continue;
        int temp =  buildDATrie(base + i, root->next[i], tree);
        ans = max(temp, ans);
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; ++i) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void clearDATrie(DATrie *tree) {
    if (!tree) return;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

void output(Node *root, int k, char *buff) {
    if (!root) return;
    if (root->flag == 1) {
        cout << buff << endl;
        return ;
    }
    buff[k + 1] = '\0';
    for (int i = 0; i < BASE; ++i) {
        if (!root->next[i]) continue;
        buff[k] = BEGIN_LETTER + i;
        output(root->next[i], k + 1, buff);
    }
    return ;
}

int main() {
    int n, cnt = 1, cnt2 = 0;
    char str[1000];
    cin >> n;
    Node *root = getNewNode();
    while (n--) {
        cin >> str;
        cnt += insert(root, str);
    }
    output(root, 0, str);
    DATrie *tree = getDATrie(cnt * BASE + 5);
    cnt2 = buildDATrie(tree->root, root, tree);
    cout << cnt2 << endl;
    while (cin >> str) {
        cout << "search " << str << ", result = " << (query(tree, str) ? "Yes" : "False") << endl;
    }
    int mem1 = cnt * sizeof(Node), mem2 = sizeof(int) * 2 * cnt2 + sizeof(int)  * 2;
    cout << "Trie memory : " << mem1 << " Bytes" << endl;
    cout << "Double-Array-Trie memory : " << mem2 << " Bytes" << endl;
    cout << "Rate : " << double(mem1 * 1.0 / mem2) << endl;
    clearDATrie(tree);
    clear(root);
    return 0;
}
