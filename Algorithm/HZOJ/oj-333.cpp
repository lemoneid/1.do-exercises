/*************************************************************************
	> File Name: oj-333.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月23日 星期五 15时44分49秒
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
#define MAX_N 500000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define SUM(ind) (tree[ind].sum)
#define MAX(ind) (tree[ind].m)
#define LM(ind) (tree[ind].lm)
#define RM(ind) (tree[ind].rm)

struct Node {
    int sum, m, lm, rm;
    int lind, rind;
} tree[(MAX_N << 1) + 5];

int root = 3, cnt = 4, ans = 0, temp = 1;
int arr[MAX_N + 5];
inline int getNode() { return cnt++; }

void UP(int a, int b, int c) {
    SUM(a) = SUM(b) + SUM(c);
    LM(a) = max(LM(b), SUM(b) + LM(c));
    RM(a) = max(RM(c), SUM(c) + RM(b));
    MAX(a) = max(MAX(b), MAX(c));
    MAX(a) = max(MAX(a), RM(b) + LM(c));
    return ;
}

void UP(int ind) {
    UP(ind ,lc(ind), rc(ind));
}

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = MAX(ind) = LM(ind) = RM(ind) = arr[l];
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
        SUM(ind) = MAX(ind) = LM(ind) =  RM(ind) = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

void query(int ind, int x, int y, int l, int r) {
    //线段树区间合并的技巧，查询时，节点的访问顺序：由范围从小到大
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    build(root, 1, n);
    for (int i  = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            if (b > c) swap(b, c);
            query(root, b, c, 1, n);
            cout << MAX(ans) << endl;
        } else {
            modify(root, b, c, 1, n);
        }
    }
    return 0;
}
