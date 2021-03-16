/*************************************************************************
	> File Name: 1.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 21时45分59秒
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

const int MAX_N = 999;
int calc(int x) {
    return (x + MAX_N / x * x) * (MAX_N / x) / 2;
}

int main() {
    int ans = 0;
    cout << calc(3) + calc(5) - calc(15) << endl;
    return 0;
}
