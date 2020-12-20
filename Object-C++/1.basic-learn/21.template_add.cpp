/*************************************************************************
	> File Name: 21.template_add.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月16日 星期三 21时27分52秒
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

class A {
public : 
    A() = delete;
    A(int x) : x(x) {}
    double operator+(int x) {
        return x + this->x + 0.001;
    }
    int x;
};

//decltype(T() + U()) add(T a, U b) {
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(add(*a, *b)) {
    return add(*a, *b);
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;
    cout << add(3, 2.5) << endl;
    cout << add(2.5, 3) << endl;
    int a;
    double b;
    typeof(a + b) c = 1; 
    cout << sizeof(c) << endl;
    decltype (a + b) d;
    cout << sizeof(d) << endl;
    A e(6);
    double f = 2;
    cout << add(e, 4) << endl;
    cout << add(&e, &f) << endl;
    return 0;
}
