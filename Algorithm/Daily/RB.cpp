/*************************************************************************
    > File Name: RB.cpp
    > Author: yanzhiwei
    > Mail: 1931248856@qq.com
    > Created Time: 2021年02月24日 星期三 23时54分03秒
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
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

struct Node {
    int key, color;
    Node *lchild, *rchild;
};

Node __NIL, *const NIL = &__NIL;
__attribute__((constructor))
void __init() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

bool hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        goto __insert_end;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
__insert_end :
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != BLACK) return root;
    if (root->rchild->color == DOUBLE_BLACK) {
        if (root->lchild->color == RED) {
            root->lchild->color = BLACK;
            root->color = RED;
            root = right_rotate(root);
            root->rchild = erase_maintain(root);
            return root;
        }
        if (!hasRedChild(root->rchild)) {
            root->rchild->color -= 1;
            root->lchild->color -= 1;
            root->color += 1;
            return root;
        }
        if (root->lchild->lchild->color == RED) {
            root->lchild->color = RED;
            root->lchild->rchild->color = BLACK;
            root->lchild = left_rotate(root->lchild);
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    }
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            temp->color += root->color;
            return temp;
        }
        Node *temp = predecessor(temp);
        root->key = temp->key;
        root->lchild = __erase(root->lchild, temp->key);
    }
    return erase_maintain(root); 
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {

    return 0;
}
