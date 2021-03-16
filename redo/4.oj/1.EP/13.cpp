/*************************************************************************
	> File Name: 13.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月12日 星期五 15时16分40秒
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
#define MAX_N 100
int a[MAX_N + 5];
char str[MAX_N + 5];
int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", str);
        int len = strlen(str);
        a[0] = max(a[0], len);
        for (int j = 0; j < len; j++) {
            a[len - j] += str[j] - '0';
        }
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            if (i == a[0]) a[0]++;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    for (int i = a[0]; i > a[0] - 10; i--) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
