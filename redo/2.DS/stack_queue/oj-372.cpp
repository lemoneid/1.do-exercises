/*************************************************************************
	> File Name: oj-372.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 09时11分52秒
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
#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int p = 1, t1 = 0, t2 = 0;
    while (p < n) {
        while (t1 != -1 && a[p] < a[t1]) t1--;
        while (t2 != -1 && b[p] < b[t2]) t2--;
        if (t1 != t2) break;
        a[++t1] = a[p];
        b[++t2] = b[p];
        p++;
    }
    cout << p << endl; 
    return 0;
}
