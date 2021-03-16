/*************************************************************************
	> File Name: 4.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 22时44分28秒
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

bool is_valid(int x) {
    int num = x, sum = 0;
    while (num) {
        sum = sum * 10 + num % 10;
        num /= 10;
    }
    return sum == x;
}

int main() {
    int ans = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            if (!is_valid(i * j)) continue;
            ans = max(i * j, ans);
            cout << ans << " : " <<  i << " " << j << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
