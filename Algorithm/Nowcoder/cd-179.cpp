/*************************************************************************
	> File Name: cd-179.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月18日 星期三 12时46分48秒
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

struct DataType {
    int height, dist;
    DataType(int h, int d) : height(h), dist(d) {};
};
vector<Node> tree;

DataType *process(int root) {
    if (root == 0) {
        return new DataType(0, 0);
    }
    DataType *left = process(tree[root].lchild);
    DataType *right = process(tree[root].rchild);
    int height = max(left->height, right->height) + 1;
    int dist = max(left->height + right->height + 1, max(left->dist, right->dist));
    return new DataType(height, dist);
}

int findMaxDistance(int root) {
    return process(root)->dist;
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
    cout << findMaxDistance(root) << endl;
    tree.clear();
    return 0;
}
