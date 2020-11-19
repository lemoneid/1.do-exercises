/*************************************************************************
	> File Name: cd-98.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 21时34分37秒
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
#include <string>
using namespace std;

string s;

int main() {
    cin >> s;
    s += " ";
    int cnt = 0, x = 0, flag = 0;
    while (x < s.size() - 1) {
        if (s[x] == s[x + 1]) {
            cnt++;
        } else {
            if (flag) cout << "_";
            flag = 1;
            cout << s[x] << "_" << cnt + 1;
            cnt = 0;
        }
        x++;
    }
    cout << endl;
    return 0;
}
