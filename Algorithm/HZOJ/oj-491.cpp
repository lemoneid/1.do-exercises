/*************************************************************************
	> File Name: oj-491.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月03日 星期五 09时22分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 50

long long f[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    f[0] =  1;
    for (int i = 1; i < m; i++) {
        f[i] = 2 * f[i - 1];
    }
    f[m] = 2 * f[m - 1] - 1;
    for (int i = m + 1; i <= n; ++i) {
        f[i] = 2 * f[i - 1] - f[i - m - 1];
    }
    cout << f[n] << endl;
    return 0;
}

