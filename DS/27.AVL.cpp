/*************************************************************************
	> File Name: 27.AVL.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月24日 星期六 10时55分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LH(root) root->lchild->h
#define RH(root) root->rchild->h

//#undef NULL
//#define NULL NIL

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

//使得求树高变得简单,无需判NULL
Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->h= 0 ;
    NIL->lchild = NIL->rchild = NULL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->h = 1;
    return p;
}

void UpdateHeight(Node *root) {
    root->h = (LH(root)> RH(root) ? LH(root) : RH(root)) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    //temp指向旋转后根节点
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    //从小到大
     UpdateHeight(root);
    UpdateHeight(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    //temp指向旋转后根节点
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    //从小到大
     UpdateHeight(root);
    UpdateHeight(temp);
    return temp;

}

//站在当前节点,返回调整后的根节点的值
Node *maintain(Node *root) {
    if (abs(LH(root) - RH(root)) <= 1) return root;
    if (LH(root) > RH(root)) {
        if (RH(root->lchild) > LH(root->lchild)) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);  
    } else {
        if (LH(root->rchild) > RH(root->rchild)) {
            root->rchild = right_rotate(root->rchild);
        }
        root  = left_rotate(root);
    } 
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    UpdateHeight(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild; 
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    //搜索过程的回溯过程
    UpdateHeight(root);
    return maintain(root);
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d [%d, %d]\n", root->key, root->lchild->key, root->rchild->key);
    output(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    int val, op;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1 : root = insert(root, val); break;
            case 2 : root = erase(root, val); break;
        }
        output(root);
    }
    clear(root);
    return 0;
}
