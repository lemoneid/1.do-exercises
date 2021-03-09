/*************************************************************************
	> File Name: oj-275.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年02月17日 星期三 10时11分13秒
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
#define P 100007
#define base 13
int H[MAX_N + 5];
int K[MAX_N + 5];
int inv[P];
char s[MAX_N + 5];

void init() {
    inv[1] = 1;
    for (int i = 2; i < P; ++i) {
        inv[i] = ((-(P / i) * inv[P % i]) % P + P ) % P;
    }
    K[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        K[i] = (K[i - 1] * base) % P;
    }
    for (int i = 1; s[i]; ++i) {
        H[i] = (H[i - 1] + K[i] * s[i]) % P;
    }
    return ;
}

int getH(int l, int r) {
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P ) % P;
}

int is_same(int i, int j, int n) {
    for (int k = 0; k < n; ++i) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}

int main() {
    scanf("%s", s + 1);
    int m, l1, l2, r1, r2;
    init();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int val1 = getH(l1, r1);
        int val2 = getH(l2, r2)
        if (val1 - val2) {
            printf("No\n");
        }
    }

    return 0;
}
