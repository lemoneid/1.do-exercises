/*************************************************************************
	> File Name: cd-167.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月16日 星期一 10时31分38秒
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
    int val;
    int lchild, rchild;
};
vector<Node> v;

bool isBSTNode(int x, int y, int val) {
    if (x == 0 || y == 0) return false;
    if (x == y) return true;
    if (v[x].val < val) return isBSTNode(v[x].rchild, y, val);
    else return isBSTNode(v[x].lchild, y, val);
}

int getTopoSize(int x, int y) {
    if (x && y && isBSTNode(x, y, v[y].val)) {
        return getTopoSize(x, v[y].lchild) + getTopoSize(x, v[y].rchild) + 1;
    }
    return 0;
} 

int traverse(int root) {
    if (root == 0) return 0;
    int len;
    len = getTopoSize(root, root);
    len = max(len, traverse(v[root].lchild));
    len = max(len, traverse(v[root].rchild));
    return len;
}

int main() {
    int root, n;
    scanf("%d%d", &n, &root);
    v.resize(n + 1);
    for (int i = 0, x, l, r; i < n; ++i) {
        scanf("%d%d%d", &x, &l, &r);
        v[x].val = x;
        v[x].lchild = l;
        v[x].rchild = r;
    }
    int ans = traverse(root);
    cout << ans << endl;
    return 0;
}
