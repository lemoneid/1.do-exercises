/*************************************************************************
	> File Name: 515.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 18时20分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd (b, a % b) : a);
}

int main() {
    int x, y, l, a, b;
    double res, pre;
    cin >> x >> y >> l;
    res = x * 1.0 / y;
    pre = 1000000;
    a = x, b = y;
    for (int i  = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (gcd(i, j) != 1) continue;
            double temp = i * 1.0 / j;    
            if (temp <= pre && temp >= res) {
                a = i;
                b = j;
                pre = temp;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
