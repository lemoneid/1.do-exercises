/*************************************************************************
	> File Name: cd-148.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 15时38分34秒
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

int ans[35];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0, x, id; i < n; ++i) {
        scanf("%d", &x);
        id = 0;
        while (x) {
            ans[id++] += x % k;
            x /= k;
        }
    }
    int res = 0;
    for (int i = 32; i != -1; i--) {
        res = res * k + (ans[i] % k);
    }
    printf("%d\n", res);
    return 0;
}
