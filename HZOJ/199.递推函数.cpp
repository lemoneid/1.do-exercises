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
int a[11] = {0};
int res[100005];
int main (){
    int k, m, tag = 1;
    cin >> k >> m;
    for( int i = 1; i < 11; i++ ){
        cin >> a[i];
    }
    for( int i = 0; i < 10; i++ ){
        res[i] = i % m ;
    }
    for( int i = 10; i <= k; i++){
        tag = 10;
        for( int j = i - 10 ; j < i ; j++ ){
            res[i] += a[tag] * res[j] % m;  
            tag--;
        }
        res[i] = res[i] % m;
        //cout << i << " " << res[i] << endl;
    }
    cout << res[k];
    return 0;
}
