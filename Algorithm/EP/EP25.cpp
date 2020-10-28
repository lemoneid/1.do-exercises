/*************************************************************************
	> File Name: EP25.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 19时06分18秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const int max_n = 1000;

int fib[3][max_n + 5] = {{1, 0}, {1, 1}, {1, 1}};

int main() {
    int n = 2;
    while (fib[n % 3][0] < 1000) {
        ++n;
        int *a = fib[n % 3], *b= fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        for (int i = 1; i <= b[0]; ++i) {
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for (int i = 1; i <= a[0]; ++i) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }
    cout << n << endl;
    return 0;
}
