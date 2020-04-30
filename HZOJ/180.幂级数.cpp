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

unsigned long long pow( int n ){
    if( n == 1 ) return 2;
    if( n & 1 ){
        return pow( n / 2 ) * pow( n / 2 ) * 2;
    }else{
        return pow( n / 2 ) * pow( n / 2 ); 
    }
}

int main (){
    int n;
    cin >> n;
    cout << pow(n);
    return 0;
}
