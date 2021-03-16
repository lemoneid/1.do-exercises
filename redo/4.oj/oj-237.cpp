/*************************************************************************
	> File Name: oj-237.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 12时37分57秒
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
int num[15];
int check[15];
int cnt;

void p(int n) {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int left, int n) {
    if (left == 0) {
        p(n);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        num[cnt++] = i;
        check[i] = 1;
        func(left - 1, n);
        check[i] = 0;
        cnt--;
    }
}

int main() {
    int n;
    cin >> n;
    func(n, n);
    return 0;
}
