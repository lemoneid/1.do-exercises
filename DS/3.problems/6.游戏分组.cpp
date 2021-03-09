/*************************************************************************
	> File Name: 6.游戏分组.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月22日 星期一 21时52分33秒
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
#define MAX_N 1000000

class UnionSet {
public :
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        fa[aa] = bb;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        u.merge(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (u.get(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;           
}
