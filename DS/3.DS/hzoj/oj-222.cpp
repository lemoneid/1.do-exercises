/*************************************************************************
	> File Name: oj-222.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月04日 星期四 11时40分01秒
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
#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)
struct node {
    int sum;
} tree[(MAX_N << 2) + 5];

int root = 1;
int arr[MAX_N + 5];

void UP(int ind) {
    tree[ind].sum = tree[lc(ind)].sum + tree[rc(ind)].sum;
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
    if (l == r) {
        //if (l != x) { //修改超界
        tree[ind].sum = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

int query(int ind, int x, int y, int l, int r) {
    if ( x <= l && r <= y ) {
        return tree[ind].sum;
    }
    int ans = 0, mid = (l + r) >> 1;
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, y);
    return ans;
}

int main() {
    int n, m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            modify(root, b, c, 1, n);
        } else if (a == 2) {
            cout << query(root, b, c, 1, n) << endl;
        }
    }

    return 0;
}
