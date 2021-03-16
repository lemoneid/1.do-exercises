/*************************************************************************
	> File Name: 47.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 17时50分26秒
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
#define MAX_N 1000000
int f[MAX_N + 5];
int prime[MAX_N + 5];
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i, f[i] = 1;
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j ++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i];
                break;
            } else {
                f[i * prime[j]] = f[i] + 1;
            }
        }
    }
}

int main() {
    init();
    int cnt = 4;
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] == 4) cnt--;
        else cnt = 4;
        if (!cnt) {
            cout << i - 3 << endl;
            break;
        }
    }
    return 0;
}
