/*************************************************************************
	> File Name: oj-231.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 10时32分56秒
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
int f[15], dp[15];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 14; i++) {
        dp[i] = 2 * dp[i - 1] + 1;
    }
    f[0] = 0;
    f[1] = 1;
    for (int i  = 2; i < 13; i++) {
        f[i] = 0x3f3f3f3f;
        for (int j = 1; j < i; j++) {
            f[i] = min(f[i], dp[i - j] + 2 * f[j]);
        }
    }
    cout << f[n] << endl;
    return 0;
}    
