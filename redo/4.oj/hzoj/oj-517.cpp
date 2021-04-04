/*************************************************************************
	> File Name: oj-517.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 21时56分38秒
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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1, I = n / 3; i <= I; i++) {
        for (int j = i, J = n - i; j <= J / 2; j++) {
            int z = n - i - j;
            if (i + j > z) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
