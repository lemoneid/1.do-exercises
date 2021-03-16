/*************************************************************************
	> File Name: 29.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 16时12分51秒
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
#define MAX_M 10000

#ifdef _D
#define log(frm, args...) {\
    printf(frm, ##args);\
}
#else
#define log(frm, ...)
#endif

struct Tuple {
    int p, times;
} num[MAX_N * MAX_N][4];
int prime[MAX_N * MAX_N + 5];
int cnt;
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        prime[i] = i;
        for (int j = i * i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    cnt = 0;
    memset(num, 0, sizeof(num));
}

void get_num(int a, int b, Tuple *temp) {
    int len = 0;
    while (a != 1)  {
        int pre = prime[a], times = 0;
        while (a % pre == 0) {
            times++, a /= pre;
        } 
        temp[len].p = pre;
        temp[len].times = times * b;
        len++;
    }
    return ;
}


int main() {
    init();
    for (int a = 2; a <= MAX_N; a++) {
        for (int b = 2; b <= MAX_N; b++) {
            Tuple temp[4] = {0};
            get_num(a, b, temp);
            int flag = 1;
            for (int k = 0; k < cnt && flag; k++) {
                flag = memcmp(num[k], temp, sizeof(temp));
            }
            if (!flag) continue;
            memcpy(num[cnt++], temp, sizeof(temp));
        }
    }
    cout << cnt << endl;
    return 0;
}
