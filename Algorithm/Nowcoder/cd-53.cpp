/*************************************************************************
	> File Name: cd-53.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 15时55分12秒
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
#define MAX_N 100000
int a[MAX_N + 5], b[MAX_N + 5];
int n;

int func(int x) {
    if (b[x] < 0) return 0;
    int oil = b[x];
    int cur = (x + 1) % n;
    while (cur != x) {
        oil += b[cur];
        if (oil < 0) return 0;
        cur = (cur + 1) % n;
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        b[i] = a[i] - b[i];
    }

    for (int i = 0; i < n; ++i) {
        int ans = func(i);
        i && printf(" "); 
        printf("%d", ans);
    }
    printf("\n");

    return 0;
}
