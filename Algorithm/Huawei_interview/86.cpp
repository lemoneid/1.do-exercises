/*************************************************************************
	> File Name: 86.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 16时07分35秒
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
    int n;
    while (cin >> n) {
        int ans = 0, cur = 0;
        while (n) {
            while (n && n % 2 == 0) n /= 2;
            while (n && n % 2 == 1) {
                cur++;
                n /= 2;
            }
            ans = max(cur, ans);
            cur = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
