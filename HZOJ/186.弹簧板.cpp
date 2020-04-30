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
int a[1000005], n;
int f( long long sum, int cnt ){
    if( sum >= n ) return cnt;
    
    return f( sum + a[ sum+1 ] , cnt + 1);
}


int main (){
    int cnt = 0;
    cin >> n;
    for( int  i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    cnt = f( 0, 0 );
    cout << cnt;


    return 0;
}
