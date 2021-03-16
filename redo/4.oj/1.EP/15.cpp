/*************************************************************************
	> File Name: 15.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 19时09分10秒
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

int main() {
    long long ans = 1, n = 40, m = 20;
    while (n > 20) {
        ans *= n--;
        while (m != 1 && ans % m == 0) {
            ans /= m;
            m--;
        }
    } 
    cout << ans << endl;
    return 0;
}
