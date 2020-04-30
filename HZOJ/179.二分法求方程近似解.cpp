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
double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double mid = 0, left = -20, right = 20;
    double num = f( p, q, mid );
    int tag = 0;
    if( f( p, q, left ) >= 0 ){
        tag = 1;
    }
    while(  fabs(num) >= EPSILON ){
        if( num > 0  ){
            if( tag == 1 ){
                left = mid;
            }
            else{
                right = mid;
            }
        }else{
            if(tag == 1){
                right = mid;
            }else{
                left = mid;
            }
        }
       // cout << " left = " << left << " right = " << right << endl; 
        mid = ( left + right ) / 2.0;
        num = f( p, q, mid );
    }
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}

