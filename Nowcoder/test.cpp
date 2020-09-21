/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月21日 星期一 19时06分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

int main() {
    int a, res = 0;
    cin >> a;
    while (a) {
        res += a & 1;
        a >>= 1;
    }
    cout << res << endl;
    return 0;
}
