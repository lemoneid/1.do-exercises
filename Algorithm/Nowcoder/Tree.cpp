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
    int n, fa, lch, rch, rootVal, val;
    scanf("%d%d", &n, &rootVal);
    Node *root, *new_node;
    map<int, Node *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &fa, &lch, &rch, &val);
        if (mp.find(fa) == mp.end()) {
            new_node = getNode(val);
            mp[fa] = new_node;
            if (fa == rootVal) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = getNode(lch); 
            mp[lch] = new_node;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = getNode(rch); 
            mp[rch] = new_node;
        }
        mp[fa]->val = val;
        mp[fa]->lchild = (lch ? mp[lch] : NULL);
        mp[fa]->rchild = (rch ? mp[rch] : NULL);
    }
    return root;
}

void preorder(Node *root) {
    if (root == NULL) return;
    cout << root->val << endl;
    preorder(root->lchild); 
    preorder(root->rchild); 
}

int dfs(Node *root, int sum, int len, int &ans) {
    if (root == NULL) {
        return 0;
    } 
    sum -= root->val;
    if (sum == 0 && len > ans) {
        ans = len;
    }
    dfs(root->lchild, sum, len + 1, ans);
    dfs(root->rchild, sum, len + 1, ans);
    return 0;
}

int findSum(Node *root, int sum) {
    if (root == NULL) return 0;
    int l1, l2, l3;
    l1 = l2 = l3 = 0;
    dfs(root, sum, 1, l1);
    l2 = findSum(root->lchild, sum);
    l3 = findSum(root->rchild, sum);
    return max(l1, max(l2, l3));
} 

int main() {
    Node *root = input(); 
    int sum;
    scanf("%d", &sum);
    int ans = findSum(root, sum);
    cout << ans << endl;
    return 0;
}

