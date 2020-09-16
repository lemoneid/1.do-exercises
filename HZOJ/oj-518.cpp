/*************************************************************************
	> File Name: oj-518.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 18时09分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long ans = 0;
    int x, add = 1, pre = 1;
    cin >> x;
    for (int i = 1; i <= x; ++i) {
        if (!add) add = ++pre;
            ans += pre;
            add--;
    }
    cout << ans << endl;
    return 0;
}
