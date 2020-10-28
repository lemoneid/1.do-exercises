/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main (){
    int x, n, sum = 0;
    cin >> x >> n;
    while( x < 6 && n > 0 ){
        sum++;
        n--;
        x++;
    }
    n -= 2;
    if( n > 0 ){
        sum = sum + n / 7 * 5 + n % 7;
        if( n % 7 == 6 ){
            sum--;
        }
    }
    cout << sum * 2;
    return 0;
}
