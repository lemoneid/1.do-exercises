/*************************************************************************
	> File Name: oj-327.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月21日 星期三 21时45分45秒
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
#define MAX_N 20000
#define MAX_M 100000

struct Data {
    int i, j, c;
} arr[MAX_M + 5];

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            val[i] = 0;
        }
        return ;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    int merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            return (val[a] - val[b] - c) % 2 == 0;
        }
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 2) % 2;
        return 1;
    }

};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].i >> arr[i].j >> arr[i].c;
    }
    sort(arr,  arr + m, [](const Data &a, const Data &b){
        return a.c > b.c;
    });
    for (int i = 0; i < m; ++i) {
        if (u.merge(arr[i].i, arr[i].j, 1)) continue;
        cout << arr[i].c << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
