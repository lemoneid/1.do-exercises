/*************************************************************************
 *
	> File Name: cd-170.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月16日 星期一 12时20分07秒
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
    int data, lchild, rchild;
};
vector<Node> tree1;
vector<Node> tree2;

bool isSameTree(int p, int q) {
    if (q == 0) return true;
    if (p == 0) return false;
    if (tree1[p].data != tree2[q].data) return false;
    return isSameTree(tree1[p].rchild, tree2[q].rchild) && isSameTree(tree1[p].lchild, tree2[q].lchild);
}

bool findTree(int p, int q) {
    if (p == 0) return false;
    bool res = isSameTree(p, q);
    if (res == true) return true; 
    res |= findTree(tree1[p].lchild, q);
    if (res == true) return true; 
    res |= findTree(tree1[p].rchild, q);
    return res;
}

void preorder(int root) {
    if (root == 0) return ;
    cout << root << endl;
    preorder(tree1[root].lchild);
    preorder(tree1[root].rchild);
}

int main() {
    int n1, n2, root1, root2;
    scanf("%d%d", &n1, &root1);
    tree1.resize(n1 + 1);
    for (int i = 0, fa, l, r; i < n1; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree1[fa].data = fa;
        tree1[fa].lchild = l;
        tree1[fa].rchild = r;
    }
    scanf("%d%d", &n2, &root2);
    tree2.resize(n2 + 1);
    for (int i = 0, fa, l, r; i < n2; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree2[fa].data = fa;
        tree2[fa].lchild = l;
        tree2[fa].rchild = r;
    }
    bool ans = findTree(root1, root2);
    cout << (ans ? "true" : "false") << endl;
    tree1.clear();
    tree2.clear();
    return 0;
}
