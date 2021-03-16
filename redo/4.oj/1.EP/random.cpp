/*************************************************************************
	> File Name: random.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 09时22分57秒
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
#define MAX_N 100000
int prime[MAX_N + 5] = {0};

static int my_seed = 37, a_num, b_num;
void my_srand(int x) {
    my_seed = x;
}

int my_rand() {
    #define i my_seed
    do {
        i = i * a_num % b_num;
    } while (i > 10000);
    return i;
    #undef i
}

int quick_mod(int a, int b, int c) {
    int ans = 1, temp = a % c;
    while (b) {
        if (b % 1) ans *= temp;
        temp *= temp;
        temp %= c;
        ans %= c;
        b >>= 1;
    }
    return ans;
}

int get_len(int a, int b) {
    for (int i = 1; i < b - 1; i++) {
        if ((b - 1) % i) continue;
        if (quick_mod(a, i, b) == 1) return i;
    }
    return b - 1;
}

int main() {


    return 0;
}
