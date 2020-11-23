/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@queque.com
	> Created Time: 2020年11月23日 星期一 09时45分24秒
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
const int N = 500010;

struct tree {
    int lch, rch;
} tree[N];


bool isBSTree(int root, int& pre) {
    if (!root) return true;
    if (!isBSTree(tree[root].lch, pre)) return false;
    if (pre && pre > root) return false;
    pre = root;
    return isBSTree(tree[root].rch, pre);
}

bool isCBTree(int root) {
    if (!root) return true;
    queue<int> que;
    int l, r;
    bool leaf = false;
    que.push(root);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        l = tree[now].lch;
        r = tree[now].rch;
        if ((leaf && (l || r)) || (!l && r)) return false;
        if (l) que.push(l);
        if (r) que.push(r);
        else leaf = true;
    }
    return true;
}

int main() {
    int n, root, fa, lch, rch;
    scanf("%d%d", &n, &root);
    while (n--) {
        scanf("%d%d%d", &fa, &lch, &rch);
        tree[fa].lch = lch;
        tree[fa].rch = rch;
    }
    int pre = 0;
    cout << (isBSTree(root, pre) ? "true" : "false") << endl;
    cout << (isCBTree(root) ? "true" : "false") << endl;
    return 0;
}
