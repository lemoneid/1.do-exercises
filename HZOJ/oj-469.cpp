/*************************************************************************
	> File Name: oj-469.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 15时47分04秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string num;
    long long val = 1;
    int x, ans = 0;
    cin >> x >> num;
    for (int i = num.size() - 1; i >= 0; --i) {
        ans += (num[i] - '0') * val;
        val *= x;
    }
    cout << ans << endl;
    return 0;
}
