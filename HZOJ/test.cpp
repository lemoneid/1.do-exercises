/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月05日 星期一 20时49分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];

int main() {
    int n, p = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int top1 = -1, top2 = -1;
    while (p < n) {
        while (top1 != -1 && a[p] < a[top1]) --top1;
        while (top2 != -1 && b[p] < b[top2]) --top2;
        if (top1 != top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p += 1;
    }
    cout << p << endl;
    return 0;
}
