/*************************************************************************
	> File Name: oj-325.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月22日 星期四 14时14分35秒
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
#define MAX_N 10000
struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    int merge(int x, int y, int t) {
        int a = get(x), b = get(y);
        if (a == b) {
            return (val[x] - val[y] - t ) % 2 == 0;
        }
        fa[a] = b;
        val[a] = (val[y] - val[x] + t + 2) % 2;
        return 1;
    }
};

UnionSet u;
map<int, int> ind;
int ind_cnt;

struct Data {
   int x, y;
   string t;
} arr[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].x >> arr[i].y >> arr[i].t;
        arr[i].y += 1;
        ind[arr[i].x] = 0;
        ind[arr[i].y] = 0;
    }
    for (auto iter = ind.begin(); iter != ind.end(); iter++) {
        iter->second = (++ind_cnt);
    }
    u.init(ind_cnt);
    for (int i = 0; i < m; ++i) {
        if (u.merge(ind[arr[i].x], ind[arr[i].y], arr[i].t[0] == 'o')) continue;
        cout << i << endl;
        return 0;
    }
    cout << m << endl;
    return 0;
}
