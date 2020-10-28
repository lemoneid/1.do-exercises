/*************************************************************************
	> File Name: oj-56.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月02日 星期二 18时06分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_m 100000
#define max_n 10

int num[max_n + 5];
int fac[max_n + 5];

void init() {
    fac[0] = 1;
    fac[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return ;
}

int get_num(int k , int val, int &x) {
    int setp = k / val;
    for (int t = 0; t <= setp; x += (t <= setp)) {
        t += num[x];
    }
    num[x] = 0;
    k %= val;
    return k;
}

int main() {
    init();
    int k, x;
    cin >> x >> k;
    k -= 1;
    for (int i = x - 1; i >= 0; --i) {
        int x = 0;
        k = get_num(k, fac[i], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
