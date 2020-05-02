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

int a[1005], n;
int go( int p, int k ){
    while( k-- ){
        do{
            p = ( p + n ) % n + 1;
        }while( a[p] == 0 );
    }
    return p;
}
int main(){
    int k, left, p = 0, tag;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    left = n;
    while( left > 1 ){
        p = go( p, k);
        left--;
        a[p] = 0;
    }
    for( int i = 1; i <= n; i++ ){
        if( a[i] ){
            cout << a[i];
            break;
        }
    }

    return 0;
}




