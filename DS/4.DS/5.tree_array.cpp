/*************************************************************************
	> File Name: 5.tree_array.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月16日 星期二 15时09分37秒
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
#define lowbit(x) (x & -x)
int c[MAX_N + 5];

void add(int i , int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int n, m, pre = 0, a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        add(i, a - pre, n);
        pre = a;
    }
    cin >> m;
    char s[10];
    int l, r, x;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        switch (s[0]) {
            case 'C' : {
                cin >> l >> r >> x;
                add(l, x, n);
                add(r + 1, -x , n);
            } break;
            case 'Q' : {
                cin >> x;
                cout << query(x) << endl;
            } break;
        }
    }
    return 0;
}
