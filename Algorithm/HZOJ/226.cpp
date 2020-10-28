/*************************************************************************
	> File Name: 226.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月22日 星期二 08时59分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

int mul(int a, int b, int p) {
    int ans = 0;
    if (b > a) swap(a, b);
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = 2 * a % p;
        b >>= 1;
    }
    return ans % p;
}

int calc(int a, int b, int p) {
    int ans  = 1;
    while (b) {
        if (b & 1) ans = mul(a, ans, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans % p;
}

int main() {
int a, b, p;
    cin >> a >> b >> p;
    cout << calc(a, b, p);
    return 0;
}
