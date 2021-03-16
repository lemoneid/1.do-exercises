/*************************************************************************
	> File Name: 282.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 08时12分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAX_N 3200000
#define BASE 30

struct Node {
    int num;
    int next[2];
} tree[MAX_N + 5];
const int root = 1;
int cnt = 1;
inline int getNode() { return ++cnt; };
int arr[MAX_N + 5];

void insert(int num) {
    int p = root;
    for (int i = BASE; i>= 0; i--) {
        int ind = !!((1 << i) & num);
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].num = num;
    return ;
}

int query(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        int rind = !ind;
        if (tree[p].next[rind] == 0) p = tree[p].next[ind];
        else p = tree[p].next[rind];
    }
    return num ^ tree[p].num;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> arr[i];
        insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    cout << ans << endl;
    return 0;
}
