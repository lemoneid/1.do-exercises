/*************************************************************************
	> File Name: Tree.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 19时21分18秒
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
using namespace std;
#define MAX_N 1000000
struct Node{
    int val;
    struct Node *lchild, *rchild;
};

Node *getNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->val = val;
    return p;
}

Node *input() {
    int n, fa, lch, rch, val;
    scanf("%d%d", &n, &val);
    Node *root, *new_node;
    map<int, Node *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = getNode(val);
            mp[fa] = new_node;
            if (fa == val) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = getNode(lch); 
            mp[lch] = new_node;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = getNode(rch); 
            mp[rch] = new_node;
        }
        mp[fa]->lchild = (lch ? mp[lch] : NULL);
        mp[fa]->rchild = (rch ? mp[rch] : NULL);
    }
    return root;
}

void preorder(Node *root) {
    if (root == NULL) {
        printf("#!");
        return ;
    } 
    printf("%d!", root->val);
    preorder(root->lchild);
    preorder(root->rchild);
}

void BFS(Node *root) {
    queue<Node *> que;
    que.push(root);
    int id = 0;
    while (!que.empty()) {
        Node *cur = que.front();    
        que.pop();
        if (cur == NULL) {
            printf("#!");
            continue;
        }
        printf("%d!", cur->val);
        que.push(cur->lchild);
        que.push(cur->rchild);
    }
}

int main() {
    Node *root = input(); 
    preorder(root); 
    printf("\n");
    BFS(root);
    printf("\n");
    return 0;
}

