/*************************************************************************
	> File Name: 2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 22时26分18秒
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
#define MAX_N 4000000

int main() {
    long long a = 1, b = 2;
    long long ans = 2;
    while (a + b < MAX_N) {
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        ans += b;
    }
    cout << ans << endl;
    return 0;
}
