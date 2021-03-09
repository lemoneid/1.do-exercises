/*************************************************************************
	> File Name: 1.biary_search.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月13日 星期六 11时48分59秒
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

#define KEY(p) (p ? p->key : 0)
#define SIZE(p) (p ? p->size : 0)
#define L(p) (p ? p->lchild : nullptr)

typedef struct Node {
    int key, size;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = nullptr;
    return p;
}

void updataSize(Node *root) {
    root->size = SIZE(root->lchild) + SIZE(root->rchild) + 1;
}

Node *insert(Node *root, int val) {
    if (!root) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key > val) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    updataSize(root);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp && temp->lchild) temp = temp->lchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (!root) return root;
    if (root->key > val) {
        root->lchild = erase(root->lchild, val);
    } else if (root->key < val) {
        root->rchild = erase(root->rchild, val);
    } else {
        if (!root->lchild || !root->rchild) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        }
        Node *pre = predecessor(root);
        root->key = pre->key;
        root->lchild = erase(root->lchild, root->key);
    }
    updataSize(root);
    return root;
}

int search(Node *root, int val) {
    if (!root) return 0;
    if (root->key == val) return 1;
    if (root->key > val) return search(root->lchild, val);
    return search(root->rchild, val);
}

int search_k(Node *root, int k) {
    if (!root) return -1;
    if (SIZE(L(root)) == k - 1) return root->key;
    if (k <= SIZE(root)) return search_k(root->lchild, k);
    return search_k(root->rchild, SIZE(L(root)) + 1);
}


void print(Node *root) {
    if (!root) return ;
    printf("(%d[%d], %d, %d)\n", KEY(root), SIZE(root), KEY(root->lchild), KEY(root->rchild));
}


void output(Node *root) {
    if (!root) return ;
    output(root->lchild);
    print(root);
    output(root->rchild);
    return ;
}

void output_k(Node *root, int k) {
    if (!root || k == 0) return ;
    if (SIZE(L(root)) >= k) {
        output_k(root->lchild, k);
    } else {
        output(root);
        output_k(root->rchild, k - SIZE(L(root)) - 1);
    }
    return ;
}

void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
  int op, val;
    Node *root =  NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: printf("search %d, result : %d\n", val, search(root, val)); break;
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: {
                printf("search k = %d, result : %d\n", 
                    val, search_k(root, val)); 
            } break;
            case 4: { 
                printf("output top-%d elements\n", val);
                output_k(root, val); 
                printf("------------\n");
            } break;
        }
        if (op == 1 || op == 2) {
            output(root);
            printf("------------\n");
        }
    }


    return 0;
}
