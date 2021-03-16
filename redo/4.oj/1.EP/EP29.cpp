/*************************************************************************
	> File Name: EP29.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 13时43分24秒
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

#define MAX_N 100

typedef struct Tuple {
    int p, times;
} Tuple;

typedef struct BigInt {
   int p_num;
   Tuple p[4];
} BigInt;

int prime[MAX_N + 5];
int num_len;
BigInt num[MAX_N * MAX_N];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    num_len = 0;
    memset(num, 0, sizeof(num));
}

void add(int a, int b) {
    int times, pre_num, ind;
    while (a != 1) {
        pre_num = prime[a];
        times = 0;
        while (prime[a] == pre_num) {
            times++;
            a /= prime[a];
        }
        ind = num[num_len].p_num;
        num[num_len].p[ind].p= pre_num;
        num[num_len].p[ind].times = times * b;
        num[num_len].p_num++;
    }
    num_len++;
}

int cmp(const void *a, const void *b) {
    return memcmp(a, b, sizeof(BigInt));
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = 2; j <= MAX_N; j++) {
            add(i, j);
        }
    }
    qsort(num, num_len, sizeof(BigInt), cmp);
    int total = 1;
    for (int i = 1; i < num_len; i++) {
        if (cmp(&num[i], &num[i - 1]) == 0) continue;
        total++;
    }
    cout << total << endl;
    return 0;
}
