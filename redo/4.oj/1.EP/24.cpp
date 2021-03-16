/*************************************************************************
	> File Name: 24.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 12时45分11秒
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
#define MAX_M 1000000
#define max_n  10
int f[max_n + 5];
int check[MAX_M + 5];

void init() {
    f[0] = 1;
    for (int i = 1; i < 10; i++) {
        f[i] = f[i - 1] * i;
    }
    return ;
}

int get_num(int k, int val, int &x) {
    int step = k / val; 
    x = 0;
    for (int i = 0; i <= step;) {
        i += !check[x];
        if (i <= step) x++;
    }
    check[x] = 1;
    k %= val;
    return k;
}

int main() {
    init();
    int k = MAX_M - 1;
    for (int i = max_n - 1; i >= 0; i--) {
        int x;
        k =  get_num(k, f[i], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
