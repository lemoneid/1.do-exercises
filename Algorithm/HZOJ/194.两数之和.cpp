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

const int mmax = 100005;
int a[mmax];

int bisection(int *a, int len, int s, int y);
int main() {
    int n, s,tag = 0;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    cin >> s;
    for( int y = 1; y < n; y++ ){
        if( bisection( a, n, s, y ) > 0 ){
            //cout << bisection ( a, n, s, y ) << " " << y<<  endl;
            tag = 1;
            break;
        }
    }
    if( tag == 0 ){
        cout << "No";
    }else{
        cout << "Yes";
    }
    return 0;
}

int bisection(int *a, int len, int s, int y) {
    int left = y + 1, right = len;
    int mid;
    while( left <=right  ){
        mid = ( left + right ) / 2;
        if( a[mid] + a[y] - s == 0  ){
                return mid;
        }else if( a[mid] + a[y] - s < 0 ){
                left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
        return -1;
}



