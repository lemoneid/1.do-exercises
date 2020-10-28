/*************************************************************************
	> File Name: EP05.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月10日 星期日 14时34分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a,int b) {
    return (b ? gcd(b, a%b) : a);
}

int main() {
    int ans = 1;
    for (int i = 2; i < 21; i++) {
        ans *= i / gcd(ans, i);
    }
    cout << ans << endl;
    return 0;
}
