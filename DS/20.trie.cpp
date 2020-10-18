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

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        p = p->next[code(str[i])];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; ++i) {
        if (p->next[code(str[i])] == NULL) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return ;
}

void output(Node *root, int k, char *buff) {
    if (k == 0) printf("\nPrintf the word\n");
    if (root == NULL) return ;
    if (root->flag == 1) {
        printf("%s\n", buff);
    }
    for (int i =  0; i < BASE; ++i) {
        buff[k] = BASE_LETTER + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
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

int main() {
    char str[1000];
    int n;
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "YES" : "NO");
    }
    clear(root);     
    return 0;
}
