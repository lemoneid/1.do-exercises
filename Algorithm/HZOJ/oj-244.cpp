/*************************************************************************
	> File Name: oj-244.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月23日 星期二 14时37分16秒
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

#define MAX_N 100000
struct Node {
    int sum, t1, t2;
} tree[(MAX_N << 2) + 5];
int arr[MAX_N + 5];

void UP(int ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
}

void mul_tag(int ind, int x) {
    tree[ind].sum *=  x;
    tree[ind].t1 *= x;
    tree[ind].t2 *= x;
}

void add_tag(int ind, int x) {

}

void build(int ind, int l, int r) {
    tree[ind].t1 = 1;
    tree[ind].t2 = 0;
    if (l == r) {
        tree[l].sum = arr[l];
        return ;
    }mZ    int mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    UP(ind);
    return ;
}

void DOWN(int ind) {
    if (tree[ind].t1 - 1 || tre[ind].t2) {
        int a = tree[ind].t1, b = tree[ind].t2;
        tre[ind << 1].sum *= a;
        tree[ind << 1].t1 *= a;
        tree[ind << 1].t2 +

        tree[ind].t1 = 1;
        tree[ind].t2 = 0;
    }
}

void modify(int ind, int flag, int x, int y, int val, int l, int r) {
    if (x <= l && r <= y) {
        if (flag == 0) {
            tree[ind].sum *= val;
            tree[ind].t1 *= val;
            tree[ind].t2 *= val;
        } else {
            tree[ind].sum += (r - l + 1) * val;
            tree[ind].t2 += val;
        }
    }
    int mid = (l + r) >> 1;
    DOWN(ind);
    if (x <= mid) modify(ind << 1, flag, x, y, val, l, mid);
    if (y > mid) modify(ind << 1, flag, x, y, val, mid + 1, r);
    return ;
}
    

int main() {


    return 0;
}
