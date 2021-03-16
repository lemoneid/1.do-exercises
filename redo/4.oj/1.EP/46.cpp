/*************************************************************************
	> File Name: 46.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 17时29分35秒
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
int prime[MAX_N + 5];
int check[MAX_N + 5];
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!check[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i < MAX_N; j++) {
            check[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int func(int x) {
    return 2 * x * x;
}

bool binary_search(int (*f)(int), int x) {
    int l = 0, r = x, mid;
    cout << x << " ---- " << endl;
    while (l <= r) {
        mid = (l + r) >> 1;
        cout << mid << endl;
        if (f(mid) == x) return 1;
        if (f(mid) < x) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int is_val(int x) {
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) {
        //printf("%d vs %d + \n", x, prime[i]);
        if (binary_search(func, x - prime[i])) return 0;
    }
    return 1;
}

int main() {
    init();
    for (int x = 9; ; x += 2) {
        if (!check[x]) continue;
        if (is_val(x)) {
            cout << x << endl;
            break;
        }
    }
    return 0;
}
