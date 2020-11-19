/*************************************************************************
	> File Name: cd-172.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 17时48分43秒
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
vector<Node> tree;

int isBalance(int root) {
    if (root == 0) return 0;
    int lh = isBalance(tree[root].lchild);
    int rh = isBalance(tree[root].rchild);
    if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

int main() {
   int n, root;
    scanf("%d%d", &n, &root);
    tree.resize(n + 1);
    for (int i = 0, fa, l, r; i < n; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree[fa].data = fa;
        tree[fa].lchild = l;
        tree[fa].rchild = r;
    }
    int ans = isBalance(root);
    printf("%s\n", ans != -1 ? "true" : "false");
    tree.clear();
    return 0;
}
