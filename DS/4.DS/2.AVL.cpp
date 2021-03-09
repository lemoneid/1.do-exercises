/*************************************************************************
	> File Name: 2.AVL.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月13日 星期六 23时37分05秒
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
#define H(root) (root)->h
#define K(root) (root)->key
#define L(root) (root)->lchild
#define R(root) (root)->rchild

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL, *const NIL = &__NIL;
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild  = NIL->rchild = nullptr;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void updata_height(Node *root) {
    H(root) = max(H(L(root)) , H(R(root))) + 1;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updata_height(root);
    updata_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updata_height(root);
    updata_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(R(L(root))) > H(L(L(root)))) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (H(L(R(root))) > H(R(R(root)))) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->key  == val) return root;
    if (root->key > val) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    updata_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return root;
    if (root->key > val) {
        root->lchild = insert(root->lchild, val);
    } else if (root->key < val) {
        root->rchild = insert(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->lchild = erase(root->lchild, root->key);
    }
    return maintain(root);
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("(%d, %d, %d)\n", K(root), K(L(root)), K(R(root)));
    output(root->rchild);
    return ;
}

int main() {
    #define MAX_OP 20
    Node *root = NIL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    output(root);
    int val;
    while (~scanf("%d", &val)) {
        root = erase(root, val);
        printf("erase %d from AVL tree\n", val);
        output(root);
    }
    return 0;
}
