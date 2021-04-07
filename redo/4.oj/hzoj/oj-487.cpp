/*************************************************************************
	> File Name: oj-487.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 19时32分14秒
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

int main() {
    int n, ans, a = 2, b = 2;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        b = a + b;
        a = b - a;
    }
    cout << b << endl;
    return 0;
}
