/*************************************************************************
	> File Name: cd-75.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月13日 星期五 15时56分10秒
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, num, ans = 0;
    cin >> n >> num;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ans = ans ? 1 : x == num;
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
