/*************************************************************************
	> File Name: oj-520.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 19时44分13秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    long long a, n, k;
    cin >> a;
    k = a;
    while (1) {
        n  = sqrt(2 * k * k + 0.25) - 0.5;
        if (n * n + n == 2 * k * k) break;
        k++;
    }
    cout << k << " " << n << endl;
    return 0;
}
