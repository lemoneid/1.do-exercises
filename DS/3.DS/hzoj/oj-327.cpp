/*************************************************************************
	> File Name: oj-327.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月31日 星期日 16时01分48秒
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
#define MAX_N 20000
#define MAX_M 100000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }

    int merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            return (val[a] - val[b] + 2) % 2;
        }
        fa[aa] = bb;
        val[aa] = (val[b] - val[a] + 3) % 2;
        return 1;
    }

};

struct Data {
    int a, b, c;
} arr[MAX_M + 5];

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    sort(arr, arr + m, [](const Data &a, const Data &b) {
        return a.c > b.c;
    });
    for (int i = 0; i < m; ++i) {
        if (!u.merge(arr[i].a, arr[i].b)) {
            cout << arr[i].c << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
