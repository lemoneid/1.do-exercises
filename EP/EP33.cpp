/*************************************************************************
	> File Name: EP33.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月30日 星期六 16时21分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int eg(int i, int j, int *x, int *y) {
    int a[2] = {i % 10, i / 10};
    int b[2] = {j % 10, j / 10};
    for (int m = 0; m < 2; ++m) {
        for (int n = 0; n < 2; ++n) {
            if (a[m] == b[n]) {
                *x = a[m ^ 1];
                *y = b[n ^ 1];
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int x, y;
    int k = 0;
    int sum_x = 1, sum_y = 1;
    for (int i = 11; i < 100; ++i) {
        if (i % 10 == 0) continue;
        for (int j = i + 1; j < 100; ++j) {
            if (!eg(i, j, &x, &y)) continue;
            if (x * j == y * i) {
                sum_x *= x;
                sum_y *= y;
                printf("i = %d, j = %d, x = %d, y = %d\n", i, j, x, y);

            } 
                
        }
    }    
    cout << sum_x << " " << sum_y << endl;
    cout << sum_y / (gcd(sum_x, sum_y)) << endl;
    return 0;
}
