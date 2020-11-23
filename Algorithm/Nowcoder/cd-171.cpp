/*************************************************************************
	> File Name: cd-171.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 09时56分10秒
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
const int MAX_N = 500000;
struct Node {
    int lchild, rchild;
};
Node tree1[MAX_N + 5];
Node tree2[MAX_N + 5];
//vector<Node> tree1;
//vector<Node> tree2;

bool isSameTree(int root1, int root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1 != root2) false;
    return isSameTree(tree1[root1].lchild, tree2[root2].lchild) && isSameTree(tree1[root1].rchild, tree2[root2].rchild);
}

bool findBegin(int root1, int root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1 == root2 && isSameTree(root1, root2)) return true;
    else return findBegin(tree1[root1].lchild, root2) || findBegin(tree1[root1].rchild, root2);
}

int main() {
    int n1, n2, root1, root2;
    scanf("%d%d", &n1, &root1);
    //tree1.resize(n1 + 1);
    for (int i = 0, fa, l, r; i < n1; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree1[fa].lchild = l;
        tree1[fa].rchild = r;
    }
    scanf("%d%d", &n2, &root2);
    //tree2.resize(n2 + 1);
    for (int i = 0, fa, l, r; i < n2; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree2[fa].lchild = l;
        tree2[fa].rchild = r;
    }
    bool ans = findBegin(root1, root2);
    cout << (ans ? "true" : "false") << endl;
    return 0;
}
