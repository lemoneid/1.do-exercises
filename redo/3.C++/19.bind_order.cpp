/*************************************************************************
	> File Name: 19.bind_order.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月19日 星期一 14时44分50秒
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

void func(int &x) {
    cout << __PRETTY_FUNCTION__ << " called " << endl;
    return ;
}

int main() {
    int x = 10;
    func(x);
    cout << x << endl;
    return 0;
}
