/*************************************************************************
	> File Name: EP19.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月04日 星期四 18时12分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int Date(int y, int m, int d) {
    if (m <= 2) m += 12, --y;
    int h = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y /100 + y / 400 + 1) % 7;
    return h;
}

int main() {
    int cnt = 0;
    for (int y = 1901; y <= 2000; ++y) {
        for (int m = 1; m < 13; ++m) {
            if (Date(y, m, 0) == 1) {
                cnt++;
            }
        }
    } 
    cout << cnt << endl;
    return 0;
}
