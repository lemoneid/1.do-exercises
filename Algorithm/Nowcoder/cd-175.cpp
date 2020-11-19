/*************************************************************************
	> File Name: ../Nowcoder/cd-175.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月17日 星期二 18时30分46秒
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
vector<int> arr;
void lastorder(int root) {
    if (root == 0) return ;
    lastorder(tree[root].lchild);
    arr.push_back(root);
    lastorder(tree[root].rchild);
    return ;
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
    lastorder(root);
    int x, ans = 0;
    scanf("%d", &x);
    for (auto iter = (arr.begin() + 1); iter != arr.end(); iter++) {
        if (*(iter - 1) == x) {
            tree.clear();
            cout << *iter << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    tree.clear();
    return 0;
}
