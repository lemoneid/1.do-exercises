/*************************************************************************
	> File Name: 82.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 15时43分37秒
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
int getLen(const string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return (r - l - 1);
}

int main() {
    string s;
    while (cin >> s) {
        int size = s.size();
        int ans = size ? 0 : 1;
        for (int i = 0; i < size - 1; i++) {
            ans = max(ans, max(getLen(s, i, i), getLen(s, i, i + 1)));
        }
        cout << ans << endl;
    }

    return 0;
}
