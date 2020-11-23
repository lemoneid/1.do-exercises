/*************************************************************************
	> File Name: cd-109-1.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 17时52分48秒
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

int main() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 2; i <= n; ++i) res = (res + m) % i;
    cout << res + 1 << endl;
    return 0;
}
