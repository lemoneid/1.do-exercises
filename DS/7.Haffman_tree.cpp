/*************************************************************************
    > File Name: 7.Haffman_tree.cpp
    > Author: weier 
    > Mail: 1931248856@qq.com
    > Created Time: 2020年06月28日 星期日 18时42分50秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max_n 1000
#define swap(a, b) {\
    __typeof(a) _temp = a;\
    a = b; b = _temp;\
}
typedef struct Node {
    char data;
    double p;
    struct Node *next[2];
} Node;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct Haffman_Tree {
    Node *root; 
    int n;
    Code *codes;
} Haffman_Tree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[max_n + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

Haffman_Tree *getNewtree(int n) {
    Haffman_Tree *tree = (Haffman_Tree *)malloc(sizeof(Haffman_Tree));
    tree->root = NULL;
    tree->n = n;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    return tree;
}
/*
void insertOnce(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
    return ;
}
*/
void insertOnce(Node **arr, int n) {
    //if (n == 0) return ;
    while (n && arr[n]->p > arr[n - 1]->p) {
        swap(arr[n], arr[n - 1]);
        --n;
        //if (n == 0) break;
    }
    return ;
}
int extract_Codes(Node *root, Code *arr, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[k].ch = root->data;
        arr[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    //delta 为 haffman叶子节点数
    delta += extract_Codes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extract_Codes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

Haffman_Tree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc (sizeof(Node *) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; ++i) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; --i) {
        Node *p = getNewNode(NULL); 
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = nodes[i -1]->p + nodes[i]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char *) * n);
    Haffman_Tree *tree =  getNewtree(n);
    tree->root = nodes[0];
    extract_Codes(tree->root, tree->codes, 0, 0, buff);
    free(nodes);
    return tree;
}



int main() {
    int n;
    char str[10];
    scanf("%d", &n); 
    for (int i = 0; i < n; ++i) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    Haffman_Tree *tree = build(arr, n);
    for (int i = 0; i < tree->n; ++i) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
