/*************************************************************************
	> File Name: 30.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 09时58分30秒
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

#define MAX_N 354294

int main() {
    long long sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        int temp = i, x = 0;;
        while (temp) {
            x += pow(temp % 10, 5);
            temp /= 10;
        }
        if (x == i) sum += i;
    }
    cout << sum << endl;

    return 0;
}
