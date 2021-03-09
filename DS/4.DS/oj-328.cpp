/*************************************************************************
	> File Name: oj-328.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月16日 星期二 17时13分41秒
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
#define MAX_N 200000
long long c[MAX_N + 5];
#define lowbit(x) (x & -x)

void add(long long i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

long long query(int i, int n) {
    long long sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

long long n;
long long val[MAX_N + 5];

void read() {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    return ;
}

void solve(long long &x, long long &y) {
    x = y = 0;
    for (long long i = 1; i <= n; ++i) {
        long long a1 = query(val[i], n);
        long long a2 = val[i] - a1 - 1;
        long long b1 = i - a1 - 1;
        long long b2 = n - val[i] - b1;
        x += b1 * b2;
        y += a1 * a2;
        add(val[i], 1, n);
    }
    
}

int main() {
    read();
    long long a, b;
    solve(a, b);
    cout << a << " " << b << endl;
    return 0;
}
