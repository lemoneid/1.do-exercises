/*************************************************************************
	> File Name: 490.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月25日 星期日 11时44分44秒
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
#define MAX_N 32767
int f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;
    }
    int x = n;
    while (f[x] - x) x = f[x];
    cout << n + x << endl;
    return 0;
}
