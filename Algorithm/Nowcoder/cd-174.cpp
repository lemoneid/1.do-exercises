/*************************************************************************
	> File Name: cd-174.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 21时23分34秒
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
struct Node {
    int lchild, rchild;
};

vector<Node> tree;

bool isBSTree(int root, int &pre) {
    if (!root) return true;
    if (!isBSTree(tree[root].lchild, pre)) return false;
    if (pre && pre > root) return false;
    pre = root;
    return isBSTree(tree[root].rchild, pre);
}

bool isCBTree(int root) {
    if (!root) return true;
    queue<int> que;
    bool leaf = false;
    int l = 0, r = 0;
    que.push(root);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        l = tree[cur].lchild;
        r = tree[cur].rchild;
        if ((leaf && (l || r)) || (!l && r)) return false;
        if (l) que.push(l);
        if (r) que.push(r);
        else leaf = false;
    }
    return true;
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    if (!n) {
        cout << "false" << endl; 
        cout << "false" << endl; 
        return 0;
    }
    tree.resize(n + 1);
    for (int i = 0, fa, l, r; i < n; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree[fa].lchild = l;
        tree[fa].rchild = r;
    }
    int pre = 0;
    puts(isBSTree(root, pre) ? "true" : "false");
    puts(isCBTree(root) ? "true" : "false");
    return 0;
}
