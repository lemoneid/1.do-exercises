/*************************************************************************
	> File Name: oj-487.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月02日 星期四 09时38分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long  C(int m,int n) {
    n = min(n, m - n);
    long long ans = 1;
    for (int i = m - n; m > i; --m) {
        ans *= m;
        while (ans % n == 0 && n != 1) {
            ans /= n;
            --n;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    long long ans = 2;
    if (n > 2) {
        long long a = n - 2, b = 1, temp = 0;
        while (a >= b) {
            temp += C(a--, b++);
        }
        ans += 2 * temp;
    }
    cout << ans << endl;
    return 0;
}
