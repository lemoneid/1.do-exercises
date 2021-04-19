/*************************************************************************
	> File Name: 17.cas.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 22时31分57秒
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
class testClass{
public :
    static constexpr auto y = 123;
    int x = 123;
private :
};

constexpr int func(int a) {
    return a * 2;
}


class A {
public:
    constexpr A(int x) {}
};

int f(int x) {
    return 2 * x;
}

int main() {
    
    int n;
    cin >> n;
    const int t1 = n + 2;
    constexpr int t2 = func(2);
    const A m1(123);
    constexpr A m2(123);



    auto x = 12.3;
    const type_info &xt = typeid(x);
    cout << typeid(x).name() << endl;
    cout << typeid(x).hash_code() << endl;
    cout << (typeid(x).hash_code() == typeid(double).hash_code());
    cout << endl;
    const int a = 123;
    constexpr int b = 123;
    cout << "&a : " << &a << endl;
    cout << "&b : " << &b << endl;
    cout << "(const_cast<int *>(&a)) = " << (const_cast<int *>(&a)) << endl;
    cout << "(const_cast<int *>(&b)) = " << (const_cast<int *>(&b)) << endl;
    cout << "*(&a) : " << *(&a) << endl;
    *(const_cast<int *>(&a)) = 456;
    *(const_cast<int *>(&b)) = 789;
    cout << "*(const_cast<int *>(&a)) = 456" << endl;
    cout << "*(const_cast<int *>(&b)) = 789" << endl;
    cout << a << " " << b << endl;
    cout << "a  : " << a << endl;
    cout << "*(&a) : " << *(&a) << endl;
    cout << "b  : " << b << endl;
    cout << "*(&b) : " << *(&b) << endl;
    return 0;
}
