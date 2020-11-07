/*************************************************************************
	> File Name: oj-231.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月04日 星期三 17时25分41秒
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
    int f[15] = {0, 1}, ans[15];
    for (int i = 2; i < 14; ++i) {
        f[i] = 2 * f[i - 1] + 1;
    }
    memset(ans, 0x3F, sizeof(ans));
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < 13; ++i) {
        for (int j = 1; j < i; ++j) {
            ans[i] = min(ans[i], ans[j] * 2 + f[i - j]);
        }
    }
    int n;
    cin >> n;
    cout << ans[n] << endl;
}
