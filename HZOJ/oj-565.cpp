/*************************************************************************
	> File Name: oj-565.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri 14 Aug 2020 09:44:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, ans;
    cin >> n;
    ans = ( n >> 16  & 0x0000ffff) | (n << 16 & 0xffff0000);
    cout << ans;
    return 0;
}
