#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
#define swap(a, b) {\
    __typeof(a) _temp = a;\
    a = b; b = _temp;\
}

const int MAX_N = 1000;

typedef struct Node {
    char ch;
    double p;
    struct  Node *next[2];
} Node;

typedef struct Code {
    char ch;
    char *str;
};


typedef struct HaffmanTree {
    int n;
    Node *root;
    Code *codes;
} HaffmanTree;

typedef struct Data {
    char ch;
    double p;
} Data;

Data arr[MAX_N + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = nullptr;
    return p;
}

HaffmanTree *getNewTree(int n) {
    HaffmanTree *t = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    t->root = nullptr;
    t->n = n;
    t->codes = (Code *)malloc(sizeof(Code) * n);
    return t;
}

void insertOnce(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
        }
        break;
    }
    return ;
}

int extractCodes(Node *root, Code *arr, int k, int l, char *buff) {
    if (!root->next[0] && !root->next[1]) {
        arr[k].ch = root->ch;
        arr[k].str = strdup(buff); 
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; ++i) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(nullptr);
        p->next[0] = nodes[i];
        p->next[1] = nodes[i - 1];
        p->p = p->next[0]->p + p->next[1]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *t = getNewTree(n);
    t->root = nodes[0];
    extractCodes(t->root, t->codes, 0, 0, buff);
    free(nodes);
    return t;
}

void output(Node *root) {
    if (!root) return ;
    queue<pair<Node *, int> > q;
    q.push({root, 0});
    int pre = 0;
    while (!q.empty()) {
        auto temp = q.front();
        Node *cur = temp.first;
        int l = temp.second;
        q.pop();
        if (pre != l) {
            pre = l;
            cout << endl;
        }
        cout << cur->ch << " ";
        if (cur->next[0]) q.push({root->next[0], l + 1});
        if (cur->next[1]) q.push({root->next[1], l + 1});
    }
}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);
    //output(tree->root);
    for (int i = 0; i < tree->n; ++i) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
