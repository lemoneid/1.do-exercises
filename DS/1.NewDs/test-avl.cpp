/*************************************************************************
	> File Name: test-avl.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月05日 星期四 18时41分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <ctime>
using namespace std;
#define LH(root) root->lchild->h
#define RH(root) root->rchild->h

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL, *NIL = &__NIL;
__attribute__((constructor)) 
void init_NIL() {
    NIL->key = NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void updataHeligth(Node *root) {
    root->h = max(LH(root), RH(root)) + 1;
}

Node *leftRotate(Node *root) {
    cout << "--leftRotate--" << endl;
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updataHeligth(root);
    updataHeligth(temp);
    return temp;
}

Node *rightRotate(Node *root) {
    cout << "--rightRotate--" << endl;
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updataHeligth(root);
    updataHeligth(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(LH(root) - RH(root)) < 2) return root;
    if (LH(root) > RH(root)) {
        if (RH(root->lchild) > LH(root->lchild)) {
            root->lchild = leftRotate(root->lchild);
        }
        root = rightRotate(root);
    } else {
        if (LH(root->rchild) > RH(root->rchild)) {
            root->rchild = rightRotate(root->rchild);
        }
        root = leftRotate(root);
    }
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) return root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    updataHeligth(root);
    return maintain(root);
}

Node *precessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            return root->lchild == NIL ? root->rchild : root->lchild;
        } 
        Node *pre = precessor(root);
        root->key = pre->key;
        root->lchild = erase(root->lchild, pre->key);
    }
    updataHeligth(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void __output(Node *root) {
    if (root == NIL) return ;
    __output(root->lchild);
    printf("(%d, %d, %d)\n", root->key, root->lchild->key, root->rchild->key);
    __output(root->rchild);
    return ;
}

void output(Node *root) {
    printf("AVL tree : ==========\n");
    __output(root);
    printf("---------------------\n");
    return ;
}

int main() {
    srand(time(0));
    Node *root = NIL;
    int key;
    for (int i = 0; i < 20; ++i) {
        key = rand() % 100;
        cout <<  "insert : " << key << " ";
        root = insert(root, key);
        output(root);
    }
    while (cin >> key) {
        cout << "erase : " << key << endl;
        root = erase(root, key);
        output(root);
        cout << endl;
    }

    return 0;
}
