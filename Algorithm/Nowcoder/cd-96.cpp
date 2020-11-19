/*************************************************************************
	> File Name: cd-96.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 09时31分27秒
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

int len1, len2;
string n, m;

int main() {
    cin >> len1 >> len2 >> n >> m;
    m = m + m;
    int ans = m.find(n);
    if (len1 != len2 || ans < 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << endl;
    return 0;
}
