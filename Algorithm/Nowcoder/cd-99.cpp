/*************************************************************************
	> File Name: cd-99.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 10时07分00秒
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
#define MAX_N 100000
string beg, s;
int n, ans = -1;


int main() {
    cin >> n >> beg;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (ans == -1 && s == beg) ans = i;
    }
    cout << ans << endl;

    return 0;
}
