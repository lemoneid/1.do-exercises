/*************************************************************************
	> File Name: oj-236.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 12时25分01秒
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
int num[15], cnt = 0;
int n, m;

void p() {
    for (int i = 0; i < m; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int start, int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = start; i <= n - left + 1; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);

    return 0;
}
