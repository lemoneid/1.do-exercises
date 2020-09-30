/*************************************************************************
	> File Name: hafffman_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 30 Sep 2020 06:18:26 PM CST
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}


typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct Data {
    char ch;
    double p;
} Data;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct Haffman_Tree {
    Node *root;
    int n;
    Code *codes;
} Haffman_Tree;

Data arr[1000];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = obj ? obj->ch : 0;
    p->p = obj ? obj->p : 0;
    p->next[0] = p->next[1] = NULL;
    return p;
}

Haffman_Tree *init_tree(int n) {
    Haffman_Tree *tree = (Haffman_Tree *)malloc(sizeof(Haffman_Tree));
    tree->root = NULL;
    tree->n = n;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    return tree;
}

void insert_once(Node **arr, int n) {
    for (int j = n;  j > 0; --j) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
}

int build_code(Node *root, Code *arr, int ind, int l, char *buff) {
    buff[l] = 0;
    printf("start \n");
    if (root->next[0] == NULL) {
        printf("success\n");
        arr[ind].ch = root->ch;
        arr[ind].str = strdup(buff);
        return 1;
    }
    printf("right\n");
    int delta = 0;
    buff[l] = '0';
    delta += build_code(root->next[0], arr, ind + delta, l + 1, buff);
    buff[l] = '1';
    delta += build_code(root->next[1], arr, ind + delta, l + 1, buff);
    return delta;
}


void build_tree(Haffman_Tree *tree, Data *arr) {
    int n = tree->n;
    Node **nodes= (Node **)malloc(sizeof(Node) * n); 
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 0; i < n; ++i) {
        insert_once(nodes, i);
    }
    for (int i = n - 1; i > 0; --i) {
        Node *p = getNewNode(NULL);
        p->p = nodes[i]->p + nodes[i - 1]->p;
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        nodes[i - 1] = p;
        printf("%lf ", nodes[i - 1]->p);
        insert_once(nodes, i - 1);
    }
    tree->root = nodes[0];
    char *buff = (char *)malloc(sizeof(char) * n);
    build_code(tree->root, tree->codes, 0, 0, buff);
    printf("----\n");
    free(buff);
    return ;
}


int main() {
    int n;
    double p;
    char str[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%lf",str, &p);
        arr[i].ch = str[0];
        arr[i].p = p;
    }
    Haffman_Tree *tree = init_tree(n);
    build_tree(tree, arr);
    for (int i = 0; i < n; ++i) {
        printf("%c %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
