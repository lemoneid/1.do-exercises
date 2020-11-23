/*************************************************************************
	> File Name: cd-122.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 14时16分46秒
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

string s1, s2, input;
int last1 = -1, last2 = -1, n, ans = 0x3f3f3f3f;
int main() {
    cin >> n >> s1 >> s2;
    if (s1.empty() || s2.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == s1) {
            if (last2 != -1) {
                ans = min(ans, i - last2);
            }
            last1 = i;
        }
        if (input == s2) {
            if (last1 != -1) {
                ans = min(ans, i - last1);
            }
            last2 = i;
        }
    }
    if (ans == 0x3f3f3f3f) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
