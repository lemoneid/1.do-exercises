/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
#define EPSILON 1e-7
double bisection(int a, double (*func)(int, double));
double f(int a, double x);
int main() {
    int a;
    scanf("%d", &a);
    printf("%.4lf\n", bisection( a, f));
    return 0;
}

double bisection(int a, double (*func)(int, double)) {
    double mid = 10, left = 0, right = 20;
    double num = f( a, mid );
    while(  fabs(num) >= EPSILON ){
        if( num > 0  ){
                right = mid;
        }else{
                left = mid;
        }
        mid = ( left + right ) / 2.0;
        num = f( a, mid );
    }
    return mid;
}

double f(int a, double x) {
    return log(x) + x - log(a);
}


