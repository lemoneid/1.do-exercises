/*************************************************************************
	> File Name: cd-44-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 21时20分32秒
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

bool calc(string s, string aim) {
    int len1 = s.size(), len2 = aim.size();
    for (int i = 0, j = 0; i < len1;) {
        if (s[i] == aim[j]) {
            ++i, ++j;
        } else {
            ++j;
        }
        if (j == len2 && i < len1) return false;
    }
    return true;
}

int main() {
    string s1, s2, aim;
    cin >> s1 >> s2 >> aim;
    if (calc(s1, aim) && calc(s2, aim)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
