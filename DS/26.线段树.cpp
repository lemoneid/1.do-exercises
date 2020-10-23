/*************************************************************************
	> File Name: oj-222.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月23日 星期五 14时05分56秒
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
//单点修改，区间查询
//线段树开4倍空间
#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
struct node {
    long long sum;
} tree[(MAX_N << 2) + 5];

//根节点下标
int root = 1;
//原数组的值
long long arr[MAX_N + 5];

void UP(int ind) {
    tree[ind].sum = tree[lc(ind)].sum  + tree[rc(ind)].sum;
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int l, int r) {
    //可能发生修改超界 l != x
    if (l == r) {
        //if (l != x) 
        tree[ind].sum= y;
        return ;
    } 
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    //上提发生在更新之后
    UP(ind);
    return ;
}

long long query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    long long ans = 0, mid = (l + r) >> 1;
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) modify(root, b, c, 1, n);
        else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    return 0;
}
