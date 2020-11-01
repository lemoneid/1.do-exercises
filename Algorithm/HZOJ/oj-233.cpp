/*************************************************************************
	> File Name: oj-233.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月29日 星期四 17时28分03秒
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

int n, p, h, m, ans[MAX_N + 5];

int main() {
    scanf("%d%d%d%d", &n, &p, &h, &m);
    int a, b, flag;
    for (int i = 1; i <= n; ++i) ans[i] = h;
    for (int i = 0; i < m; ++i) {
        flag = 0;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        for (int j = a + 1; j < b; ++j) {
            if (ans[j] >= ans[a] || ans[j] >= ans[b]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            for (int j = a + 1; j < b; ++j) {
                ans[j] -= 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
