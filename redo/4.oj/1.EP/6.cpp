/*************************************************************************
	> File Name: 6.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 08时23分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main() {
    int sum1 = 100 * 101 / 2;
    int sum2 = 0;
    for (int i = 1; i < 101; i++) {
        sum2 += i * i;
    }
    cout << sum1 * sum1 - sum2 << endl;
    return 0;
}

