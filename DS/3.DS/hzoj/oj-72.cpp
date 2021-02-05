/*************************************************************************
	> File Name: oj-72.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月27日 星期三 22时15分43秒
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
#define MAX_N 10000

struct UnionSet {
    int father[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; ++i) father[i] = i, val[i] = 0;
    }

    int get(int x) {
        if (x == father[x]) return x;
        int root = get(father[x]);
        val[x] += val[father[x]];
        val[x] %= 3;
        return father[x] = root;
    }

    void merge(int a, int b, int c) {
        int fa = get(a), fb = get(b);
        if (fa == fb) return ;
        father[fa] = fb;
        val[fa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;

int main() {
    int n, m;
    int a, b, c;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
            continue;
        }
        if (u.get(b) != u.get(c)) {
            cout << "Unknown" << endl;
            continue;
        }
        switch ((u.val[b] - u.val[c] + 3) % 3) {
            case 0 : cout << "Tie" << endl; break;
            case 1 : cout << "Loss" << endl; break;
            case 2 : cout << "Win" << endl; break;
        }
    }

    return 0;
}
