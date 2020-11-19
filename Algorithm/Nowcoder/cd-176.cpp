/*************************************************************************
	> File Name: ../Nowcoder/cd-176.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 19时45分14秒
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

int findFather(int root, int x, int y) {
    if (root == 0 || root == x || root == y) return root;
    int left = findFather(tree[root].lchild, x, y);
    int right = findFather(tree[root].rchild, x, y);
    if (left && right) return root;
    return left != 0 ? left : right;
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    tree.resize(n + 1);
    for (int i = 0, fa, l, r; i < n; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree[fa].lchild = l;
        tree[fa].rchild = r;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    cout << findFather(root, x, y) << endl;
    tree.clear();
    return 0;
}
