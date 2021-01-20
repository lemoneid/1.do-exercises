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
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
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

void morrisPre(Node *root) {
    if (!root) return ;
    Node *cur = root, *mostRight = nullptr;
    while (cur) {
        mostRight = cur->lchild;
        if (mostRight) {
            while (mostRight->rchild && mostRight->rchild != cur) {
                mostRight = mostRight->rchild;
            }
            if (mostRight->rchild == nullptr) {
                mostRight->rchild = cur;
                cout << cur->key << " ";
                cur = cur->lchild;
                continue;
            } else {
                mostRight->rchild =nullptr;
            }
        } else {
            cout << cur->key << " ";
        }
        cur = cur->rchild;
    }
    cout << endl;
}

void morrisIn(Node *root) {
    if (!root) return ;
    Node *cur = root, *mostRight = nullptr;
    while (cur) {
        mostRight = cur->lchild;
        if (mostRight) {
            while (mostRight->rchild && mostRight->rchild != cur) {
                mostRight = mostRight->rchild;
            }
            if (mostRight->rchild == nullptr) {
                mostRight->rchild = cur;
                cur = cur->lchild;
                continue ;
            } else {
                mostRight->rchild = nullptr;
            }
        }
        cout << cur->key << " ";
        cur = cur->rchild;
    }
    return ;
}

void preOrder(Node *root) {
    if (!root) return ;
    cout << root->key << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(Node *root) {
    if (!root) return ;
    inOrder(root->lchild);
    cout << root->key << " ";
    inOrder(root->rchild);
}

void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
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
    preOrder(root);
    cout << endl;
    morrisPre(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    morrisIn(root);
    cout << endl;
    clear(root);
    return 0;
}
