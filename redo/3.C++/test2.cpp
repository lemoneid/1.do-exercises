/*************************************************************************
	> File Name: test2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月07日 星期三 20时56分33秒
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

class testClass {
public :
    static const int a = 5;
    static constexpr int b = 5;
    static constexpr double c = 5;
    int arr[b];
};
//const int testClass::a = 5;

void func(int x) {
    cout << x << endl;
}
void handler() {
    func('a');
}
void func(char x) {
    cout << x << endl;
}

int main() {
    testClass obj;
    handler();
    char c1[] = "test";
    char *c2, *c3;
    cout << typeid(c1).name() << endl;
    cout << typeid(c2).name() << endl;
    cout << typeid(c3).name() << endl;
    return 0;
}
