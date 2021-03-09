/*************************************************************************
	> File Name: haffman.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 15时04分24秒
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

struct Node {
    char ch;
    double p;
    Node *lchild, *rchild;
};

struct Code {
    char ch;
    char *str;
};

struct Data {
    char ch;
    double p;
};

struct HaffmanTree {
    Node *root;
    int n;
    Code *codes;
};

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = obj->ch ? obj->ch : 0;
    p->p = obj->p ? obj->p : 0;
    p->lchild = p->rchild = NULL;
    return p;
}

Data **init(int n) {
    Data **arr = (Data **)malloc(sizeof(Data *) * n);
    char ch;
    double p;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> p;
        arr[i] = (Data *)malloc(sizeof(Data));
        arr[i]->ch = ch;
        arr[i]->p = p;
    }
    return arr;
}

void insertOnce(Node **nodes, int n) {
    for (int i = n; i > 0; --i) {
        if (nodes[i]->p > nodes[i - 1]->p) {
            swap(nodes[i], nodes[i - 1]);
            continue;
        }
        break;
    }
}

int extract_codes(Node *root, HaffmanTree *tree, int k, int ind, char *buff) {
    if (!root) return 0;
    if (!root->lchild && !root->rchild) {
        tree->codes[ind].ch = root->ch;
        tree->codes[ind].str = strdup(buff);
        return 1;
    }
    buff[k + 1] = 0;
    buff[k] = 0;
    int leaf = 0;
    leaf += extract_codes(root->lchild, tree, k + 1, ind + leaf, buff);
    buff[k] = 1;
    leaf += extract_codes(root->rchild, tree, k + 1, ind + leaf, buff);
    return leaf;
}

HaffmanTree *build(Data **arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = getNewNode(arr[i]);
    }
    for (int i = 1; i < n; ++i) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Node *p =  getNewNode(NULL);
        p->lchild = nodes[i];
        p->rchild = nodes[i - 1];
        p->p = p->lchild->p  + p->rchild->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->root = nodes[0];
    tree->n = n;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    extract_codes(nodes[0], tree, 0, 0, buff);
    return tree;
}

int main() {
    int n;
    cin >> n;
    Data **arr = init(n);
    HaffmanTree *tree = build(arr, n);
    return 0;
}
