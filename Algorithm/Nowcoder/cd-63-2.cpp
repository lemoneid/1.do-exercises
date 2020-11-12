/*************************************************************************
	> File Name: cd-63-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 13时26分27秒
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
    int n, l, r, mmax = 0, a;
    scanf("%d%d", &n, &a);
    l = a, mmax = a;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a);
        mmax = max(mmax, a);
    }
    r = a;
    cout << mmax - min(l, r) << endl;
    return 0;
}
