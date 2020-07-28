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

int m, t, head, len, cnt, temp;

long long C(int n, int m) {
    m = min(m, n - m);
    long long ans = 1;
    for (int i = n; i > n - m; --i) {
        ans *= i;
        while (m != 1 && ans % m == 0) {
            ans /= m;
            --m;
        }
    }
    return ans;
}

int main() {
    cin >> m >> t;
    len = floor(log10(m)) + 1;
    head = m / pow(10, len - 1);
    for (int i = 1; i < len; ++i) {
        temp += C(len - 1, i) * (len - i - 1) * 9;
    }
    temp += 1;
    if (t == 0) {
        cnt = temp * head;
    } else if (head < t) {
        cnt = temp * (head + 1);
    } else {
        cnt  = head * temp;
        cnt += pow(10, len - 1);
    }
    cout << (m - cnt) << endl;
    return 0;
}
