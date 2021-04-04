/*************************************************************************
	> File Name: oj-515.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 21时25分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int A, B, L;
    cin >> A >> B >> L;
    int a = 0, b = 0;
    double rate = A * 1.0 / B;
    double pre = 1000000;
    if (A > B) {
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= i; j++) {
                if (gcd(i, j) != 1) continue;
                double x = i * 1.0 / j;
                if (x < rate) continue;
                if (x < pre) {
                    pre = x;
                    a = i;
                    b = j;
                }
            }         
        }
    } else {
        for (int i = 1; i <= L; i++) {
            for (int j = i; j <= L; j++) {
                if (gcd(i, j) != 1) continue;
                double x = i * 1.0 / j;
                if (x < rate) continue;
                if (x < pre) {
                    pre = x;
                    a = i;
                    b = j;
                }
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
