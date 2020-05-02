/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月02日 星期六 18时27分12秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int sum = 1;
    for( int l = 3; l <= 1001; l += 2 ){
        sum += 4 * l * l - 6 * l + 6;

    }
    cout << sum;
    return 0;
}
