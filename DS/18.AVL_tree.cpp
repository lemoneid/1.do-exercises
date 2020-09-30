/*************************************************************************
	> File Name: 18.AVL_tree.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月23日 星期四 20时23分12秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LH(root) (root->lchild->h)
#define RH(root) (root->lchild->h)
#define VAL(root) (root->key)
#define max(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
})

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node, *pNode;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NULL;
    NIL->h = 1;
}

pNode getNewNode(int key) {
    pNode p = (pNode) malloc (sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    p->h = 1;
    return p;
}

void update_height(pNode root) {
    root->h == max(LH(root), RH(root)) + 1;
    return ;
}

pNode left_rotate(pNode root) {
    pNode temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    //先更新root
    update_height(root);
    update_height(temp);
    return temp;
}
pNode right_rotate(pNode root) {
    pNode temp = root->rchild;
    root->lchild = temp->rchild;
    root->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}



pNode maintain(pNode root) {
    update_height(root);
    if (abs(LH(root) - RH(root) < 2)) return root;
    if (LH(root) > RH(root)) {
        if (RH(root->lchild) > LH(root->lchild)) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (LH(root->rchild) > RH(root->rchild)) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

pNode insert(pNode root, int key) {
    if (!root) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return maintain(root);
}

void clear(pNode root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void __output(pNode root) {
    if (!root) return ;
    __output(root->lchild);
    printf("%d %d %d\n", VAL(root), VAL(root->lchild), VAL(root->rchild));
    __output(root->rchild);
}

void output(pNode root) {
    printf("AVL tree : ============\n");
    __output(root);
    printf("-----------------------\n");
    return ;
}


int main() {
    srand(time(0));
    #define MAX_OP 20
    int val;
    pNode root = NIL;
    for (int i = 0; i < MAX_OP; ++i) {
        val = rand() % 100;
        root = insert(root, val);
        printf("insert %d to tree\n", val);
        output(root);
    }
    return 0;
}
