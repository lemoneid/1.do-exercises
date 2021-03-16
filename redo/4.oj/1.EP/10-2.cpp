/*************************************************************************
	> File Name: 10-2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 13时58分45秒
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

#define MAX_N 2000000
int prime[MAX_N + 5];
void init() {
    for (int i = 2; i * i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    long long sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) sum += i;
    }
    cout << sum << endl;
}

int main() {
    init();

    return 0;
}
