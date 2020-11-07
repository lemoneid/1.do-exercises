/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月02日 星期一 17时26分56秒
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
#define NORMAL 1
#define THREAD 0

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node; 

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key); 
    return root;
}

void buildThread(Node *root) {
    if (root == NULL) return;
    static Node *pre = NULL;
    buildThread(root->lchild);
    if (root->lchild == NULL) {
        root->ltag = THREAD;
        root->lchild = pre;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = THREAD;
        pre->rchild = root;
    }
    pre = root;
    buildThread(root->rchild);
    return ;
}

Node *getProcess(Node *tmp) {
    while (tmp && tmp->ltag == NORMAL && tmp->lchild) tmp = tmp->lchild;
    return tmp;
}

void inorder(Node *root) {
    if (root == NULL) return;
    static int flag = 0;
    if (!flag) cout << "inorder_thread = [";
    flag++;
    inorder(root->lchild);
    cout << root->key << " ";
    inorder(root->rchild);
}

void inorder_thread(Node *root) {
    Node *p = getProcess(root);
    cout << "inorder_thread = [";
    while (p) {
        cout << p->key << " ";
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = getProcess(p->rchild);
        }
    }
    cout <<"]" << endl;
    return ;
}

void inorder_after(Node *root) {
    if (root == NULL) return;
    static int flag = 0;
    if (!flag) cout << "inorder_thread = [";
    flag++;
    if (root->ltag == NORMAL) inorder_after(root->lchild);
    cout << root->key << " ";
    if (root->rtag == NORMAL) inorder_after(root->rchild);

}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
}


int main() {
    srand(time(0));
    #define MAX_OP 25
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; ++i) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    inorder(root);
    cout << endl;
    buildThread(root);
    inorder_thread(root);
    inorder_after(root);
    cout << endl;
    #undef MAX_OP
    return 0;
}
