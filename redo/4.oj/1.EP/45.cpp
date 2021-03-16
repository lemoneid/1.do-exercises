/*************************************************************************
	> File Name: 45.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 17时06分16秒
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

long long func1(long long n) {
    return n * (n + 1) >> 1;
}

long long func2(long long n) {
    return n * (3 * n - 1) >> 1;
}

long long func3(long long n) {
    return n * (2 * n - 1);
}

typedef long long (*func)(long long);
long long binary_search(func f, long long x) {
    long long l = 1, r = x, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (f(mid) == x) return 1;
        if (f(mid) < x) l = mid + 1;
        else r = mid - 1;
        //cout << mid << endl;
    }
    return 0;
}

int main() {
    long long x = 144;
    long long num;
    while (1) {
        num = func3(x);
        if (binary_search(func2, num) 
            && binary_search(func1, num)) {
                break;
        }
        cout << num << endl;
        x++;
    }
    cout << num << endl;
    return 0;
}
