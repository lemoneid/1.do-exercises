/*************************************************************************
	> File Name: oj-333.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月04日 星期四 14时45分02秒
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
#define MAX_N 500000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define SUM(ind) tree[ind].sum
#define MAX(ind) tree[ind].m
#define LMAX(ind) tree[ind].lm
#define RMAX(ind) tree[ind].rm

struct node {
    int sum, m, lm, rm;
    int lind, rind;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];
int root = 3, cnt = 4, ans = 0, temp = 1;
inline int getNode() { return cnt++;  }

void UP(int a, int b, int c) {
    SUM(a) = SUM(b) + SUM(c);
    LMAX(a) = max(LMAX(b), SUM(b) + LMAX(c));
    RMAX(a) = max(RMAX(c), SUM(c) + RMAX(b));
    MAX(a) = max(MAX(b), MAX(c));
    MAX(a) = max(MAX(a), RMAX(b) + LMAX(c));
    return ;
}

void UP(int ind) {
    UP(ind, lc(ind), rc(ind));
}

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = MAX(ind) = LMAX(ind) = RMAX(ind) = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    lc(ind) = getNode();
    rc(ind) = getNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int l, int r) {
    if (l == r) {
        SUM(ind) = MAX(ind) = LMAX(ind) = RMAX(ind) = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

void query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        if (x == l) tree[ans] = tree[ind];
        else {
            UP(temp, ans, ind);
            swap(temp, ans);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) query(lc(ind), x, y, l, mid);
    if (y > mid) query(rc(ind), x, y, mid + 1, r);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
    build(root, 1, n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            if (b > c) swap(b, c);
            query(root, b, c, 1, n);
            printf("%d\n", MAX(ans));
        } else {
            modify(root, b, c, 1, n);
        }
    }
    return 0;
}
