/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月02日 星期六 18时27分12秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int is_val( int n ){
    int temp = n, sum = 0;
    while( temp > 0 ){
        sum *= 10;
        sum += temp % 10;
        temp /= 10;
    }
    return sum == n;
}

int main(){
    int ans = 0;
    for( int a = 100;  a < 1000; a++ ){
        for( int b = a; b < 1000; b++ ){
            if( is_val( a * b)  && a * b > ans ){
                ans = a * b;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
