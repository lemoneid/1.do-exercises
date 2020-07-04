/*************************************************************************
	> File Name: 8.thread_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月30日 星期二 19时18分58秒
 ************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

#define NORMAL 0
#define THREAD 1

 typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
 } Node;

Node *getNewNode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = NORMAL;
    return p;
}    

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key > val) root->lchild = insert(root->lchild, val);
    else root->rchild  = insert(root->rchild, val);
    return root;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->ltag = THREAD;
        root->lchild = pre;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = THREAD;
        pre->rchild = root;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

Node * most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
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
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    Node *p = most_left(root), *q;
    while (p) {
        q = p;
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
        free(q);
    }
    return ;
}

 int main() {
    srand(time(0));
    Node *root  = NULL;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; ++i) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    in_order(root);
    printf("\n");
    output(root);
    printf("\n");
    clear(root);
    #undef MAX_OP
    return 0;
 }
