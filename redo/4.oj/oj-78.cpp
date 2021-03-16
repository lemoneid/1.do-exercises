/*************************************************************************
	> File Name: oj-78.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 22时06分10秒
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
int b[MAX_N + 5];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = 0, len2 = 0;
    for (int i = s1.size() - 1; i >= 0; i--) a[i] = s1[len1++] - '0';
    for (int i = s2.size() - 1; i >= 0; i--) b[i] = s2[len2++] - '0';
    for (int i = 0; i < len2; i++) {
        a[i] += b[i];
        if (a[i] < 10) continue;
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
        if (i + 1 == len1) len1++;
    }
    for (int i = len1 - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}
