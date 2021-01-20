#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

const int NORMAL = 0;
const int THREAD = 1;

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->ltag = p->rtag = NORMAL;
    p->lchild = p->rchild = nullptr;
    return p;
}

Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

void inorder(Node *root) {
    if (!root) return ;
    printf("%d ", root->key);
    if (root->ltag == NORMAL) inorder(root->lchild);
    if (root->rtag == NORMAL) inorder(root->rchild);
}

void buildThead(Node *root) {
    if (!root) return ;
    static Node *pre = nullptr;
    if (root->lchild == nullptr) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    if (root->ltag == NORMAL) buildThead(root->lchild);
    if (root->rtag == NORMAL) buildThead(root->rchild);
    return ;
}

void clear(Node *root) {
    if (!root) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

Node *leftMost(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *root) {
    if (!root) return ;
    //Node *p = leftMost(root);
    Node *p = root;
    while (p) {
        printf("%d ", p->key);
        if (p->ltag == NORMAL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    printf("\n");
    return ;
}

int main() {
srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    buildThead(root);
    inorder(root), printf("\n");
    output(root);
    clear(root);

    return 0;
}
