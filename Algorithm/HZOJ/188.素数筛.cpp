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
#define mmax  1000005
int  prime[mmax];

void init(){
    long long i, j;
    for( i = 3; i <= mmax; i++ ){
        if( i & 1 || i == 2){
            prime[i] = 1;
        }else{
            prime[i] = 0;
        }
    }   
    for( i = 3; i * i <= mmax; i += 2 ){
        if( prime[i] ){
            for( j = i + i ; j <= mmax; j += i ){
                prime[j] = 0; 
            }
        }
    }
}


int main (){
    long long N, M;
    cin >> N >> M;
    long long  i;
    init();
    for( i = M; i <= N; i++ ){
        if( prime[i] ){
            cout << i << endl;
        }
    }
    return 0;
}
