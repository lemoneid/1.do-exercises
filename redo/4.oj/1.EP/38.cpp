/*************************************************************************
	> File Name: 38.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 09时41分50秒
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

int is_val(int n, int *result) {
    int num = 0, a[10] = {0};
    int ret = 0, i = 1, x;
    while (num < 9) {
        x = n * i;
        while (x) {
            if (x % 10 == 0) return false;
            if (a[x % 10]) return false;
            a[x % 10] = ++num;
            x /= 10;
        }
        ret *= (int)pow(10, floor(log10(n * i)) + 1);
        ret += n * i;
        i++;
    }
    (*result) = ret;
    return true;
}

int main() {
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        int num = 0;
        if (is_val(i, &num) && num > ans)  ans = num;
    }
    cout << ans << endl;
    return 0;
}
