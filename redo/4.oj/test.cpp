/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 09时57分50秒
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

int func() {
    static int cnt = 0;
    cout << cnt << endl;
    cnt++;
}

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        func();
    }

    return 0;
}
