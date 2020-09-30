/*************************************************************************
	> File Name: 7.haffman.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 10时20分45秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_N 1000
#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b, b = _tmp;\
}

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct Haffman_Tree{
    Node *root;
    Code *codes;
    int n;
} Haffman_Tree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[MAX_N + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = obj ? obj->ch : 0;
    p->p =  obj ? obj->p : 0;
    p->next[0] = p->next[1] = NULL;
    return p;
}

Haffman_Tree *getNewTree(int n) {
    Haffman_Tree *tree = (Haffman_Tree *)malloc(sizeof(Haffman_Tree));
    tree->codes = (Code *)calloc(n, sizeof(Code));
    tree->root = NULL;
    tree->n = n;
    return tree;
}

void insertOnce(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
}

int cmp(const void *a, const void *b) {
    return ((Node *)a)->p > ((Node *)b)->p;
}

int extractCodes(Node *root, Code *arr, int ind, int l, char *buff) {
    buff[l] = 0;
    //Haffman_Tree 只有度为0和度为1
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[ind].ch = root->ch;
        arr[ind].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], arr, ind + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, ind + delta, l + 1, buff);
    return delta;
}

Haffman_Tree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr + i);
    }
    //qsort(nodes, n, sizeof(Node*), cmp);
    for (int i = 1; i < n; ++i) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL); 
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = nodes[i - 1]->p + nodes[i]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char*)calloc(n, sizeof(char));
    Haffman_Tree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
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

