/*************************************************************************
	> File Name: 19.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 19时44分56秒
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

int is_valid(int x) {
    if (x % 4 == 0 && x % 400 != 0) return 1;
    return 0;
}

int calc(int x) {
    return 30 * 4 + 7 * 31 + 28 + is_valid(x);
}

int main() {
    int day = calc(1900);
    int sum = day;
    for (int i = 1901; i <= 2000; i++) {
        sum += calc(i);
    }
    int ans = sum / 7 - day  / 7;
    cout << ans << endl;

    return 0;
}
