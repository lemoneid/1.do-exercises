/*************************************************************************
	> File Name: oj-326.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月31日 星期日 14时36分54秒
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
#define MAX_N 50000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    int merge(int a, int b, int c) {
        int aa =  fa[a], bb = fa[b];
        cout << endl;
        cout << a << ":" << aa << ":" << val[a] << endl;
        cout << b << ":" << bb << ":" << val[b] << endl;
        cout << c << endl;
        if (aa == bb) {
            return (val[a] - val[b] - c + 3) % 3 == 0;
        }
        fa[aa] = bb;
        val[aa] = ((val[b] + c - val[a]) % 3 + 3) % 3;
        return 1;
    }

};

UnionSet u;

int main() {
    int n, k, ans = 0;
    int d, x, y;
    cin >> n >> k;
    u.init(n);
    for (int i = 0; i < k; ++i) {
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (!u.merge(x, y, d - 1)) {
            cout << "i :" << i + 1 << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
