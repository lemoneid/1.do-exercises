/*************************************************************************
	> File Name: cd-57.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 21时27分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main() {
    long long num;
    cin >> num;
    long long res = 0;
    while (num != 0) {
        num >>= 1;
        res += num;
    }
    cout << res << endl;

    return 0;
}
