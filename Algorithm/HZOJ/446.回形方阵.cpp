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


int main(){
    int n, num = 1, x, y;
    int a[15][15] = {0};
    cin >> n;
    a[ x = 0 ][ y = 0 ] = 1;
    while( num <= ( n + 1 ) /2){
        while( !a[x+1][y] && x+1 < n ) a[++x][y] = num;
        while( !a[x][y+1] && y+1 < n ) a[x][++y] = num;
        while( !a[x-1][y] && x-1 >= 0 ) a[--x][y] = num;
        while( !a[x][y-1] && y-1 >= 0 ) a[x][--y] = num;
        num++;
    }
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if(j){
                cout << " ";
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}




