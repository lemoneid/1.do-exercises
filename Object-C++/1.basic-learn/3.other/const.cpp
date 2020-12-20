/*************************************************************************
	> File Name: const.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 15时54分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
const int a = 2;

void func() {
    cout << "func brfore : " << a << endl;
    const int a = 3;
    int *p = nullptr;
    cout << typeid(a).name() << " " << typeid(p).name() << endl;
    p = (int *)&a;
    *p = 4;
    cout << "func : " << a << endl;
    cout << "address:" << &a << " " << &p << endl;
    cout << *p << endl;
}

int main() {
    cout << a << endl;
    func();
    return 0;
}
