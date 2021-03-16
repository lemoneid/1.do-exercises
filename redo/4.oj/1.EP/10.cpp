/*************************************************************************
	> File Name: 10.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 13时52分14秒
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
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1;  j <= prime[0] && prime[j] * i < MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    long long ans = 0;
    for (int i = 1; i <= prime[0]; i++) ans += prime[i];
    cout << ans << endl;

    return 0;
}
