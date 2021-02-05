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
    int father[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (father[x] == x) return x;
        int root = get(father[x]);
        val[x] += val[father[x]];
        val[x] %= 3;
        return father[x] = root;
    }
    int merge(int x, int y, int c) {
        int fx =  get(x), fy = get(y);
        if (fx == fy) {
            return (val[x] - val[y] - c + 3) % 3 == 0;
        }
        father[fx] = fy;
        val[fx] = ((val[y] + c - val[x]) % 3 + 3) % 3;
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
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
