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

struct sLnt {
    int num, rnum;
};

int prime[MAX_N + 5];
int pSint[MAX_N + 5];
int dLen = 0;
sLnt d[MAX_N + 5];

int InttoSint(int n) {
    int rnum = 0;
    while (n) {
        rnum += 1 << (n % 10 * 2);
        n /= 10;
    }
    return rnum;
}

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            d[dLen].num = i;
            d[dLen].rnum = InttoSint(i);
            pSint[i] = d[dLen].rnum;
            dLen++;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]]  = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

bool cmp(sLnt a, sLnt b) {
    if (a.rnum < b.rnum) return true;
    if (a.rnum == b.rnum && a.num < b.num) return true;
    return false;
}

int main() {
    init();
    sort(d, d + dLen, cmp);
    for (int i = 0; i < dLen - 2; i++) {
        int j = i + 1, nxt;
        while (d[j].rnum == d[i].rnum) {
            nxt = 2 * d[j].num - d[i].num;
            if (nxt > MAX_N) break;
            if (pSint[nxt] == d[i].rnum) {
                printf("%d%d%d\n", d[i].num, d[j].num, nxt);
            }
            j++;
        }
    }
    return 0;
}
