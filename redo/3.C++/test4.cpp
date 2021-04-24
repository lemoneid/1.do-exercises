/*************************************************************************
	> File Name: test4.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月19日 星期一 19时58分26秒
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

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout << add(1, 2) << endl;
    cout << add(2.2, 3.3) << endl;
    cout << add<double>(2, 2.4) << endl;
    cout << add(2, 2.4) << endl;

    return 0;
}
