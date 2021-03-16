/*************************************************************************
	> File Name: 3.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 22时36分53秒
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
#include<cstdio>
#define max_m 600851475143LL   // int_64t的长整型

int main() {
    long long i = 2, x = max_m;
    long long ans = 0;
    while (i * i < x) {
        if (x % i == 0) ans = i;
        while (x % i == 0) x /= i;
        i++;
    }
    if (max_m != 1) ans = x;
    cout << ans << endl;
    return 0;
}
