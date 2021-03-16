/*************************************************************************
	> File Name: 39.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 16时40分02秒
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
#define MAX_N 1000
int cnt[MAX_N + 5];

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int i = 2; i * i < MAX_N; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) - 1) continue;
            int a = 2 * i * j;
            int b = i * i - j * j;
            int c = j * j + i * i;
            int p = a + b + c;
            for (int k = p; k <= MAX_N; k += p) {
                cnt[k]++;
            }
        }
    }
    int ind = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (cnt[i] > cnt[ind]) ind = i;
    }
    cout << ind << endl;
    return 0;
}
