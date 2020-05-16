/*************************************************************************
	> File Name: 14.NewTon.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月12日 星期二 20时25分08秒
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
#define EPSL 1e-6

inline double F(double x, double n) {
    return x * x - n;
}

inline double f(double x) {
    return 2 * x;
}

double NewTon(double (*F)(double, double), double (*f)(double), double n) {
    double x1 = n / 2.0;
    while (fabs(F(x1, n)) > EPSL) {
        x1 -= F(x1, n) / f(x1);
    }
    return x1;
}

double my_sqrt(double n) {
    return NewTon(F, f, n);
}


int main() {
    double n;
    while (~scanf("%lf", &n)) {
        cout << my_sqrt(n) << endl;
    }

    return 0;
}
