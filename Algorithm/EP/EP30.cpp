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
        sum += pow( temp % 10, 5);
        temp /= 10;
    }
    return sum == n;
}

int main(){
    int mmax = pow( 9, 5) * 6;
    int sum  = 0;
    for ( int i = 2; i <= mmax; i++ ){
        if( is_val(i) )
            sum += i;
    }
    cout << sum << endl;
    return 0;
}
