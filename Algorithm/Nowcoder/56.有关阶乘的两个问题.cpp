/*************************************************************************
	> File Name: 56.有关阶乘的两个问题.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月05日 星期一 13时50分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    long long n, res = 0;
    cin >> n;
    while (n) {
        res += n / 5;
        n /= 5;
    }
    cout << res << endl;
    return 0;
}
