/*************************************************************************
	> File Name: 20.trie.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月16日 星期五 21时19分44秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'
#define code(x) (x - 'a')

typedef struct Node {
    int flag, path;
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        p = p->next[code(str[i])];
        if (p == NULL) return 0;
    }
    return p->flag > 0;
}

void insert(Node *root, char *str) {
    Node *p = root;
    p->path++;
    for (int i = 0; str[i]; ++i) {
        int idx = code(str[i]);
        if (p->next[idx] == NULL) p->next[idx] = getNewNode();
        p = p->next[idx];
        p->path++;
    }
    p->flag++;
    return ;
}

void del(Node *root, char *str) {
    if (!query(root, str)) return ;
    Node *p = root;
    p->path++;
    for (int i = 0; str[i]; ++i) {
        int idx = code(str[i]);
        if (--((p->next[idx])->path) == 0) {
            p->next[idx] = NULL;
            return ;
        }
        p = p->next[idx];
    }
    p->flag--;
    return ;
}

int prefix(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        p = p->next[code(str[i])];
        if (p == NULL) return 0;
    }
    return p->path;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; ++i) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    char str[1000];
    int n, op;
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        memset(str, 0, sizeof(str));
        scanf("%d%s", &op, str);
        switch (op) {
            case 1 : insert(root, str); break;
            case 2 : del(root, str); break;
            case 3 : printf("%s\n", query(root, str) ? "YES" : "NO"); break;
            case 4 : printf("%d\n", prefix(root, str)); break;
            default : break;
        }
    }
    clear(root);     
    return 0;
}
