/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月28日 星期日 20时17分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *init(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->lchild = node->rchild = NULL;
    node->data = val;
    return node;
}

Node *insertNode(Node *root, int val) {
    if (root == NULL) {
        root = init(val);
        return root;
    }
    if (root->data == val) {
        return root;
    }
    if (root->data > val) {
        return insertNode(root->lchild, val);
    } else {
        return insertNode(root->rchild, val);
    }
}

Node *findPreNode (Node *root, int val) {
    static Node *pre;
    if (root->data == val) {
        return pre;
    }
    pre = root;
    if (root->data > val) {
        findPreNode(root->rchild, val);
    } else {
        findPreNode(root->lchild, val);
    }
}

Node *findNextNode (Node *node) {
    Node *temp = node->rchild;
    Node *pre = node;
    while (temp->lchild) {
        pre = temp;
        temp = temp->lchild;
    }
    if (pre == node) pre->rchild = NULL;
    else pre->lchild = NULL;
    return temp;
}

int deleteNode(Node *root, int val) {
    Node *node = insertNode(root, val);
    if (node == NULL) return 0;
    if (node->lchild == NULL && node->rchild == NULL) {
        free(node);  
        return 1;
    }
    Node *temp = findPreNode(root, node->data);
    if (node->lchild == NULL || node->rchild == NULL) {
        if (temp->lchild == NULL) {
            temp->lchild = node->rchild ? node->rchild : node->lchild;
        } else {
            temp->rchild = node->rchild ? node->rchild : node->lchild;
        }
        return 1;
    }
    if (temp->lchild == NULL) {
        temp->lchild = findNextNode(node);
    } else {
        temp->rchild = findNextNode(node);
    }
    return 1;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->data);
    output(root->rchild);
    return ;
}

int clear(Node *root) {
    if (root->lchild == NULL && root->rchild == NULL) {
        free(root);
        return 1;
    }
    root->lchild && clear(root->lchild);
    root->rchild && clear(root->rchild);
    return 1;
}

int main() {
    Node *root;
    srand(time(0));
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; ++i) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insertNode %d at %d\n", val, insertNode(root, val)->data);
            } break;
            case 3: {
                printf("deleteNode %d at %d\n", val, deleteNode(root, val));
            } break;
        }
        output(root);
        printf("\n");
    }
    clear(root);
    return 0;
}
