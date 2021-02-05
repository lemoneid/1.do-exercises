/*************************************************************************
	> File Name: oj-325.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月31日 星期日 13时48分06秒
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
#define MAX_N 5000

struct Data {
    int l, r;
    string s;
} arr[MAX_N + 5];

set<int> ind_s;
map<int ,int> ind;
int cnt = 0;

struct UnionSet {
    int father[MAX_N << 1 + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
            val[i] = 0;
        }
        return ;
    }
    
    int get(int x) {
        if (father[x] == x) return x;
        int root = get(father[x]);
        val[x] += val[father[x]];
        val[x] %= 2;
        return father[x] = root;
    }
    
    int merge(int a, int b, int c) {
        int fa = get(a), fb = get(b);
        if (fa == fb) {
            return (val[a] - val[b] - c) % 2 == 0;
        }
        father[fa] = father[fb];
        val[fa] = (c + val[b] - val[a] + 2) % 2;
        return 1;
    }
};

UnionSet u;

int main() {
    int l, q;
    cin >> l >> q;
    for (int i = 0; i < q; ++i) {
        cin >> arr[i].l >> arr[i].r >> arr[i].s;
        arr[i].r += 1;
        ind_s.insert(arr[i].l);
        ind_s.insert(arr[i].r);
    }

    for (auto cur : ind_s) {
        ind[cur] = ++cnt;
    }

    u.init(cnt);
    for (int i = 0; i < q; ++i) {
        arr[i].l = ind[arr[i].l];
        arr[i].r = ind[arr[i].r];
        if (u.merge(arr[i].l, arr[i].r, arr[i].s == "odd")) continue;
        cout << i << endl;
        return 0;
    }
    cout << q << endl;
    return 0;
}
