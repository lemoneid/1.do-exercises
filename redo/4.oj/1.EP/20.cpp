/*************************************************************************
	> File Name: 20.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 19时54分58秒
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

int a[10000];

int main() {
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= a[0]; j++) {
            a[j] *= i;
        }
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < 10) continue;
            if (j == a[0]) a[0]++;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
    }
    int sum = 0;
    for (int i = 1; i <= a[0]; i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
