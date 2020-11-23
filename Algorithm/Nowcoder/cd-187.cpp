/*************************************************************************
	> File Name: cd-187.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 16时30分04秒
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
    vector<int> child;
};

struct DataType {
    int yesAns, noAns;
    DataType (int x, int y) {
        yesAns = x;
        noAns = y;
    }
};

vector<Node> tree;

DataType process(int root) {
    int yes = tree[root].val;
    int no = 0;
    if (tree[root].child.empty()) {
        return DataType(yes, no);
    }
    for (auto cur : tree[root].child) {
        DataType res = process(cur); 
        yes += res.noAns;
        no += max(res.yesAns, res.noAns);
    }
    return DataType(yes, no);
}


int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tree[i].val);
    }
    for (int i = 1, fa, child; i < n; ++i) {
        scanf("%d%d", &fa, &child);
        tree[fa].child.push_back(child);
    }
    DataType res = process(root);
    printf("%d\n", max(res.yesAns, res.noAns));
    return 0;
}
