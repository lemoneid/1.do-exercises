/*************************************************************************
	> File Name: EP20.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月31日 星期日 16时49分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 10000

int a[max_n] = {1, 1, 0};

int main() {

    for (int i = 2; i < 101; ++i) {
        for (int j = 1; j <= a[0]; ++j) a[j] *= i;
        for (int j  = 1; j <= a[0]; ++j) {
            if (a[j] < 10) continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if (j == a[0]) a[0] += 1;
        }
    }
    long long sum = 0;
    cout << a[0] << endl; 
    for (int i = 1; i <= a[0]; ++i) {
        cout << a[i];
        sum += a[i];
    }
    cout << endl<< sum << endl;
    return 0;
}

