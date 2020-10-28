/*************************************************************************
	> File Name: 6.thread_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 30 Sep 2020 07:36:45 PM CST
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define NORMAL 0
#define THREAD 1
typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->ltag = p->rtag = NORMAL;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *build_tree(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (val < root->key) root->lchild = build_tree(root->lchild, val);
    else root->rchild = build_tree(root->rchild, val);
    return root;
}


Node *most_left(Node *root) {
    while (root && root->ltag == NORMAL && root->lchild != NULL) root = root->lchild;
    return root;
}



void thread_tree(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    thread_tree(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    } 
    pre = root;
    thread_tree(root->rchild);
    return ;
}

void output(Node *root) {
    Node *p = most_left(root);
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
   }
}

void in_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return ;
}


int main() {
    srand(time(0)); 
    Node *root = NULL;
    for (int i = 0; i < 20; ++i) {
        int val = rand() % 100;
        root = build_tree(root, val);
        printf("%d insert\n", val);
    }
    thread_tree(root);
    printf("in_order : ");
    in_order(root);
    printf("\n");
    printf("output   : ");
    output(root);
    printf("\n");
    return 0;
}
