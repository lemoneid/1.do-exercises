/*************************************************************************
	> File Name: oj-262.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 11时15分43秒
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
#define MAX_N 60000
long long f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j < i; j++) {
            sum += f[j] * f[i - j + 1];
        }
        f[i] = sum;
    }
    cout << f[n] << endl;
    return 0;
}
