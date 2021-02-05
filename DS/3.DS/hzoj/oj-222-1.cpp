/*************************************************************************
	> File Name: oj-222-1.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月04日 星期四 12时24分26秒
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
#include <climits>
using namespace std;
#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)

struct Node {
    int max_sum;
    int l, r;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];
int root = 1;

inline void update(int ind) {
    tree[ind].max_sum = max(tree[lc(ind)].max_sum, tree[rc(ind)].max_sum);
    return ;
}
void build(int ind, int l, int r) {
    tree[ind].l = l, tree[ind].r = r;
    if (l == r) {
        tree[ind].max_sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    update(ind);
    return ;
}

void modify(int ind, int k, int val) {
    if (tree[ind].l == tree[ind].r) {
        if (tree[ind].l != k) return ;
        tree[ind].max_sum = val;
        return ;
    }
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid) modify(lc(ind), k, val);
    else modify(rc(ind), k, val);
    update(ind);
    return ;
}

int query(int ind, int x, int y) {
    if (x <= tree[ind].l && tree[ind].r <= y) {
        return tree[ind].max_sum;
    }
    int ans = INT_MIN, mid = (tree[ind].l + tree[ind].r) >> 1;
    if (x <= mid) {
        ans = max(ans, query(lc(ind), x, y));
    }
    if (y > mid) {
        ans = max(ans, query(rc(ind), x, y));
    }
    return ans;
}

int main() {
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    build(root, 1, n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            modify(root, b, c);
        } else if (a == 2) {
            int ans = -2147483648;
            if (b <= c) {
                ans = query(root, b, c);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
