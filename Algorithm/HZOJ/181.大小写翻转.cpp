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

char change( char ch ){
    if( ch >= 'a' && ch <='z' ){
        return ( ch - 'a' + 'A');
    }else{
        return ( ch + 'a' - 'A' );
    }
}
int main (){
    string str;
    cin >> str;
    for( int i = 0; i < str.size(); i++ ){
        cout << change( str[i]);
    }
    return 0;
}
