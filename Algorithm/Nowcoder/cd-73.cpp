/*************************************************************************
	> File Name: cd-73.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 16时18分21秒
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

int main() {
    string str;
    cin >> str;
    int l = 0, r = str.size() - 1;
    if (str[0] == '-') l = 1;
    while (l < r) {
        if (str[l++] == str[r--]) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
