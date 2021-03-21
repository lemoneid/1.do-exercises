/*************************************************************************
	> File Name: oj-235.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 12时14分17秒
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

int n, num[15], cnt;

void p() {
    for (int i = 0; i < cnt; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
}

int func(int start) {
    for (int i = start; i <= n; i++) {
        num[cnt++] = i;
        p();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);

    return 0;
}
