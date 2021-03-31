/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月29日 星期一 12时13分04秒
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

struct A {
    A() : x(0) {
        cout << "A constructor" << endl;
    }
    A operator=(int x) {
        this->x = x;
        cout << "A =" << endl;
    }
    int x;
};

struct B {
    B() {a = 2; }
private :
    A a;
};

int main() {
    const A a;
    const B b;

    return 0;
}
