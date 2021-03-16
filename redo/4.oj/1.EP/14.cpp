/*************************************************************************
	> File Name: 14.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 15时23分47秒
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
int arr[MAX_N + 5];
int keep[MAX_N + 5];

long long get_len(long long n) {
    if (n == 1) return 1;
    if (n < MAX_N && keep[n]) return keep[n];
    long long len = 0;
    if (n & 1) len = get_len(n * 3 + 1) + 1;
    else len = get_len(n >> 1) + 1;
    if (n < MAX_N) keep[n] = len;
    return len;
}

int main() {
    long long ans = 0, len = 0;
    for (int i = 1; i < MAX_N; i++) {
        long long temp = get_len(i);
        if (temp <= len) continue;
        ans = i;
        len = temp;
    }
    cout << ans << " = " << len << endl;
    return 0;
}
