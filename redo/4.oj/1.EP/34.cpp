/*************************************************************************
	> File Name: 34.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 10时26分52秒
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

int num[10];

void init(int *num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
}

int is_val(int x) {
    int sum = 0, temp = x;
    while (temp) {
        sum += num[temp % 10];
        temp /= 10;
    }
    return sum == x;
}

int main() {
    int sum = 0;
    init(num);
    for (int i = 3, I = num[9] * 7; i < I; i++) {
        if (is_val(i)) sum += i;
    }
    cout << sum << endl;

    return 0;
}
