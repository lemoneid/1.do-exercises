/*************************************************************************
   > File Name: random.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: Sat Dec 29 09:19:54 2018
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
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
        if (b & 1) ans *= temp;
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

void init_prime() {
    for (int i = 2; 2 * i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

void get_a_and_b(int *a, int *b) {
    for (int i = 1; i <= prime[0]; i++) {
        *b = prime[i];
        if (prime[i] > 13000) break;
    }
    for (int i = 2; i < *b; i++) {
        if (get_len(i, *b) != *b - 1) continue;
        *a = i;
        break;
    }
    return ;
}

void check(int a, int b) {
    a_num = a, b_num = b;
    int vis[10001] = {0};
    for (int i = 0; i < 10000; i++) {
        int temp = my_rand();
        if (vis[temp]) {
            cout << "error" << endl;
            exit(0);
        }
        vis[temp] = 1;
    }
    cout << a << " " << b << " OK" << endl;
    return ;
}

int main() {
    init_prime();
    int a, b;
    get_a_and_b(&a, &b);
    check(a, b);
    check(11, 10009);
    check(31, 17389);
    check(13, 10067);
    check(7, 10037);
    return 0;
}

