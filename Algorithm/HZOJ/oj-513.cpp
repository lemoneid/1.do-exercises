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

<<<<<<< HEAD
int m, t, cnt;
=======
>>>>>>> dabcaf672013e81b4b2280158d8a24b61857b20d
int main() {
    int m, t, cnt = 0;
    cin >> m >> t;
    for (int i = 1; i <= m; ++i) {
<<<<<<< HEAD
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
=======
        int len = floor(log10())
    }
>>>>>>> dabcaf672013e81b4b2280158d8a24b61857b20d
    return 0;
}
