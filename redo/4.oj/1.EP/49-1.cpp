/*************************************************************************
	> File Name: 49.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 21时07分09秒
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
#define MAX_N 10000

int prime[MAX_N + 5];
bool check[MAX_N + 5];
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!check[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            check[i * prime[j]]  = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int judge(int a, int b) {
    char s1[5] = {0}, s2[5] = {0};
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    sort(s1, s1 + 4);
    sort(s2, s2 + 4);
    for (int i = 0; i < 4; i++) {
        if (s1[i] - s2[i]) return 0;
    }
    return 1;
}

int main() {
    init();
    int ind = 1;
    while (prime[ind] < 1000) ind++;
    for (int i = ind; i <= prime[0]; i++) {
        int a = prime[i];
        for (int j = i + 1; j < prime[0]; j++) {
            int b = prime[j];
            if (!judge(a, b)) continue;
            int nxt = b * 2 - a;
            if (nxt > MAX_N) continue;
            if (!check[nxt] && judge(a, nxt)) {
                cout << a << b << nxt << endl;
            }
        }
        
    }
    return 0;
}
