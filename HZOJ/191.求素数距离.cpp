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
#define mmax  8000005
int prime[mmax];

void init(){
    for( int i = 3; i <= mmax; i++ ){
        if( i & 1 || i == 2 )
            prime[i] = 1;
        else
            prime[i] = 0;
    }
    for( int i = 3; i * i <= mmax; i++ ){
        if( prime[i] ){
            for( int j = i + i; j <= mmax; j += i ){
                prime[j] = 0;
            }
        }
    }
}

int main (){
    int l, r, a = 0, b = 0, c = 0, d = 0, pre = 0;
    cin >> l >> r;
    int first = 1;
    init();
    for( int i = l; i <= r; i++ ){
        if( prime[i] == 1 ){
            if( first ){
                b = l + 1;
                pre = i;
                first = 0;
            }else{
                if( i - pre <  b - a ){
                    a = pre;
                    b = i;
                    //cout << " a = " << a << " b = " << b << endl;
                }
                if ( i - pre > d - c ){
                    c = pre;
                    d = i;
                    //cout << " c = "  << c << " d = " << d<< endl;
                }
            }
            pre = i;
        }

    }
    if( a == ( l + 1 ) || c == d ){
        cout << "There are no adjacent primes.";
    }else{
        printf("%d,%d are closest, %d,%d are most distant.", a, b, c, d);
    }
    return 0;
}
