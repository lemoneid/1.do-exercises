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
#include <unordered_map>
using namespace std;
#define MAX_N 1000000
struct Node{
    int val;
    struct Node *lchild, *rchild;
};

int ans = 0;
unordered_map<int, int> hashMap;

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
    unordered_map<int, Node *> mp;
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

int findSum(Node *root, int cur, int sum, int level) {
    if (root == NULL) {
        return 0;
    } 
    cur += root->val;
    if (!hashMap.count(cur)) hashMap[cur] = level;
    if (hashMap.count(cur - sum)) {
        ans = max(level - hashMap[cur - sum], ans);
    } 
    findSum(root->lchild, cur, sum, level + 1);
    findSum(root->rchild, cur, sum, level + 1);
    if (level == hashMap[cur]) hashMap[cur] = 0;
    return 0;
}

int main() {
    Node *root = input(); 
    int sum;
    hashMap[0] = 0;
    scanf("%d", &sum);
    findSum(root, 0, sum, 1);
    cout << ans << endl;
    return 0;
}

