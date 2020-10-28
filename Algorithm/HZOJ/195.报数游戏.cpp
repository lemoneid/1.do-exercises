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

const int mmax = 100000005 ;
int a[mmax] = {0};
int main (){
    int n, m, first = 1;
    cin >> n >> m;
    for( int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    for( int i = 0; i < m; i++ ){
        int l = 0, r = n - 1;
        int mid, num, tag = 0;
        if( first ) first = 0;
        else cout << " ";
        cin >> num;
        if( a[0] > num ){
            cout << a[0];
            tag = 1;
        }
        while( l <= r && tag == 0){
            mid = ( l + r ) / 2;
            if( a[mid] == num ){
                cout << a[mid];
                break;
            }else if( a[mid] > num ){
                r  = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if( l > r){
            cout << a[r];
        }
        
    }

    return 0;
}
