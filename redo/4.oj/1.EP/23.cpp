/*************************************************************************
	> File Name: 23.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 20时24分38秒
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
#define MAX_N 28123
int prime[MAX_N + 5];
int f[MAX_N + 5];
int mul[MAX_N + 5];
int arr[MAX_N + 5];
int check[MAX_N + 5];

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            mul[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (pow(prime[j], mul[i] + 2) - 1) / ( pow(prime[j], mul[i] + 1) - 1);
                mul[i * prime[j]] = mul[i] + 1;
                break;
            } else {
                mul[i * prime[j]] = 1;
                f[i * prime[j]] = f[i] * f[prime[j]];
            }
        }
    }
    memset(prime, 0, sizeof(prime));
    memset(mul, 0, sizeof(prime));
    for (int i = 2; i < MAX_N; i++) {
        if (f[i] > 2 * i) {
            f[++f[0]] = i;
            prime[i] = 1;
        }
    }
    return ;
}

int main() {
    init();
    int sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        int flag = 0;
        for (int j = 1; !flag && f[j] < i; ++j) {
            flag = prime[i - f[j]];
        }
        if (!flag) {
            cout << i << endl; 
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}

