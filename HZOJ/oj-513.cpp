/*************************************************************************
	> File Name: oj-513.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月23日 星期四 19时02分32秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int m, t, cnt;
int main() {
    cin >> m >> t;
    for (int i = 1; i <= m; ++i) {
        int temp = i;
        while (temp) {
            if (temp % 10 == t) {
                cnt++;
                break;
            }
            temp /= 10;
        }
    }
    cout << m - cnt << endl;
    return 0;
}
