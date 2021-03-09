/*************************************************************************
	> File Name: oj-330.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月16日 星期二 15时23分59秒
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

long long c[2][MAX_N + 5];

void add(long long k, long long i, long long x, long long n) {
    while (i <= n) {
        c[k][i] += x;
        i += lowbit(i);
    }    
    return ;
}

long long query(long long k, long long i) {
    long long sum = 0;
    while (i) {
        sum += c[k][i];
        i -= lowbit(i);
    }
    return sum;
}

long long S(long long i) {
    return (i + 1) * query(0, i) - query(1, i);
}

void modify(long long i, long long x, long long n) {
    add(0, i, x, n);
    add(1, i, i * x, n);
    return ;
}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1, pre = 0, a; i <= n; ++i) {
        scanf("%lld", &a);
        modify(i, a - pre, n);
        pre = a;
    }

    char s[10];
    for (long long i = 0, l, r, d; i < m; ++i) {
        scanf("%s", s);
         switch (s[0]) {
            case 'C' : {
                scanf("%lld%lld%lld", &l, &r, &d);
                modify(l, d, n);
                modify(r + 1, -d, n);
            } break;
            case 'Q' : {
                scanf("%lld%lld", &l, &r);
                printf("%lld\n", S(r) - S(l - 1));
            } break;
        }

    }

    return 0;
}
