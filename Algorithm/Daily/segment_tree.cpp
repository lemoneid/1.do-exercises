/*************************************************************************
	> File Name: segment_tree.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月24日 星期三 23时34分51秒
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
#define MAX_N 1000

struct Node {
    long long sum, tag;
} tree[(MAX_N << 2) + 5];

long long arr[MAX_N + 5];

void UP(int ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
}

void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        tree[ind].tag = 0;
    }
    int mid = (l + r) >> 1;
    build_tree(ind << 1, l, mid);
    build_tree(ind << 1 | 1, mid + 1, r);
    UP(ind);
}

void DOWN(int ind, int l, int r) {
    if (!tree[ind].tag) return ;
    int val = tree[ind].tag;
    int mid = (l + r) >> 1;
    tree[ind << 1].sum += val * (mid - l + 1) * val;
    tree[ind << 1].tag += val;
    tree[ind << 1 | 1].sum += val * (r - mid) * val;
    tree[ind << 1 | 1].tag += val;
    tree[ind].tag = 0;
    return ;
}

void modify(int ind, int l, int r, int x, int y, int val) {
    if (x <= l && r <= y) {
        tree[ind].sum += (r - l + 1) * val;
        tree[ind].tag += val;
        return ;
    }
    DOWN(ind, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) modify(ind << 1, l, mid, x, y, val);
    if (y > mid) modify(ind << 1 | 1, mid + 1, r, x, y, val);
    UP(ind);
    return ;
}

int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    DOWN(ind, l, r);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (x <= mid) ans += query(ind << 1, l, mid, x, y);
    if (y > mid) ans += query(ind << 1 | 1, mid + 1, r, x, y);
    return ans;

}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }
    build_tree(1, 1, n);
    long long a, b, c, d;
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        switch (a) {
            case 1: {
                scanf("%lld", &d);
                modify(1, 1, n, b, c, d);
            } break;
            case 2: {
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
            } break;
        }
    return 0;
}
