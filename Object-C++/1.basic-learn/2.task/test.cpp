/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月23日 星期三 19时07分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main() {
    int x;
    cin >> x;
    bool flag = false;
    while (x) {
        if (flag) cout << " ";
        cout << x % 10 + 1;
        flag = true;
        x /= 10;
    }
    return 0;
}
