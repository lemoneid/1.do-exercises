/*************************************************************************
	> File Name: oj-562.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri 14 Aug 2020 09:30:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, tmp;
    long ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ans ^= tmp;
    }
    cout << ans << endl;
    return 0;
}
