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
#include <unordered_map>
using namespace std;
struct Node {
    int fa, lchild, rchild;
};
vector<Node> tree;
unordered_map<int, int> mmap;

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    tree.resize(n + 1);
    for (int i = 0, fa, l, r; i < n; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        tree[fa].lchild = l;
        tree[fa].rchild = r;
        if (l) tree[l].fa = fa; 
        if (r) tree[r].fa = fa; 
    }
    int times, x, y;
    cin >> times;
    vector<int> fx, fy;
    while (times--) {
        fx.clear();
        fy.clear();
        mmap.clear();
        scanf("%d%d", &x, &y);
        while (x && x != root) fx.push_back(x), mmap[x] = 1, x = tree[x].fa;
        while (y && y != root) fy.push_back(y), y = tree[y].fa;
        fx.push_back(root), fy.push_back(root);
        mmap[root] = 1;
        for (auto iter : fy) {
            if (mmap[iter] == 1) {
                cout << iter << endl;
                break;
            }
        }
    }
    tree.clear();
    return 0;
}
