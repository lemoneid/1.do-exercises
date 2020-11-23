/*************************************************************************
	> File Name: cd-144.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 15时49分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int add(int a, int b) {
    int sum = a;
    while (b != 0) {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return sum;
}

int negNum(int n) {
    return add(~n, 1);
}

int minuss(int a, int b) {
    return add(a, negNum(b));
}

int multi(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int sign = (unsigned int) (~(a ^ b)) >> 31;
    a = a >= 0 ? a : negNum(a);
    b = b >= 0 ? b : negNum(b);
    int res = 0;
    while (b != 0) {
        if (b & 1) {
            res = add(res, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return sign ? res : negNum(res);
}

bool isNeg(int n) {
    return n < 0;
}

int divi(int a, int b) {
    if (!a || !b) return 0;
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for (int i = 31; i > -1; i = minuss(i, 1)) {
        if ((x >> i) >= y) {
            res |= (1 << i);
            x = minuss(x, y << i);
        }
    }
    return isNeg(a)^isNeg(b) ? negNum(res) : res;
}

int main() {
    int a, b;
    string op;
    cin >> a >> op >> b;
    switch (op[0]) {
        case '+' : cout << add(a, b) << endl; break;
        case '-' : cout << minuss(a, b) << endl; break;
        case '*' : cout << multi(a, b) << endl; break;
        case '\\' : cout << divi(a, b) << endl; break;
    }

    return 0;
}
