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
    int a[1000005];
    int n, x = 0, temp;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> temp;
        x ^= temp;
    }
    cout <<  x;
    return 0;
}
