/*************************************************************************
	> File Name: 1.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 11时11分54秒
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

void f(int k) {
    if (k > 0) {
        cout << k << endl;
        f(k - 1);
        f(k - 1);
    }
}

int main() {
    f(4);
    return 0;
}
