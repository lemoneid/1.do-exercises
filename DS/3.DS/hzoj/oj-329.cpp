/*************************************************************************
	> File Name: oj-329.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月03日 星期三 23时58分51秒
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
int c[MAX_N + 5];
inline int lowbit(int x) {return x & (-x); }
void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}
int query(int x) {
    int sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}
int main() {
    int n, m, pre = 0, now;
    char str[10];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now);
        add(i, now - pre, n);
        pre = now;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        switch (str[0]) {
            case 'C' : {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                add(a, c, n);
                add(b + 1, -c, n);
            } break;
            case 'Q' : {
                int x;
                scanf("%d", &x);
                printf("%d\n", query(x));
            }
        }
    }

    return 0;
}
