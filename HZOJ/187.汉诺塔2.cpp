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
int n;
long long res_cnt, res_power;
int f(int x, long long  cnt, long long power ){
    if( x == n ) {
        res_cnt = cnt;
        res_power = power;
        return 1;
    }
    cnt  = 2 * cnt + 1;
    power = 2 * power + x + 1 ;
    //cout << "cnt =  " << cnt << " power = " << power <<endl;  
    return f( x + 1,cnt, power );
}

int main (){
    cin >> n;
    f( 1, 1, 1 );
    cout << res_cnt << " " << res_power << endl;
    return 0;
}
