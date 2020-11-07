/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月05日 星期四 17时46分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define base 0.577215
#define MAX 280
const double esp = 1e-6;

double calc(int mid) {
    return (base - 1 + log(mid + 1));
}

int main() {
    double x;
    while (cin >> x) {
        if (fabs(x - 0) < esp) {
            return 0;
        }
        double sum = 0;
        int i;
        for (i = 2; i < 280; ++i) {
            sum += 1.0 / i;
            if (sum >= x) break;
        }
        cout << i - 1<< endl;
    } 
    return 0;
}
