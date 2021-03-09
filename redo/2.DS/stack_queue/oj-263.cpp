/*************************************************************************
	> File Name: oj-263.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 10时22分29秒
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
int a[30], s[30], top;

bool is_valid(int *a, int n) {
    int p = 0;
    top = -1;
    for (int i = 0; i < n; i++) {
        while (p < a[i]) {
            s[++top] = ++p;
        }
        if (top == -1 || s[top] - a[i]) return false;
        --top;
    }
    return true;
}

int main() {
    int n, ans = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if (is_valid(a, n)) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
            }
            cout << endl;
            ans--;
        }
    } while ( ans && next_permutation(a, a + n));
    return 0;
}
