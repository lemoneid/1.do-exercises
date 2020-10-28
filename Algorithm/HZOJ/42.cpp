/*************************************************************************
	> File Name: 42.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月25日 星期日 11时32分09秒
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
#define MAX_M 20
#define MAX_N 10000

int f[MAX_N + 5];

int main() {
    int n, m, val;
    cin >> m >> n;
    f[0] = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> val;
        for (int j = 1; j <= n; ++j) {
            if (j >= val) f[j] += f[j - val];
            f[j] %= 9973;
        }
    }
    cout << f[n] << endl;
    return 0;
}
