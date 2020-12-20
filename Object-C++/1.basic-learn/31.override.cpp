/*************************************************************************
	> File Name: 31.override.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 16时37分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

//struct A final { //类没有派生类,不允许被继承
struct A {
    //virtual void fun1() final {
    virtual void fun1() {
        cout << "class A : fun yi" << endl;
    }
    void funcl() {
        cout << "class A : fun ai ou" << endl;
    }
    virtual ~A() {
        cout << "class A : destructor" << endl;
    }
};

struct B : A {
    //void funcl() override { //语义严谨程序
    void funcl() {
        cout << "class B : func ai ou" << endl;
    } 
    void fun1() {
        cout << "class B ; fun yi" << endl;
    } 
    ~B() {
        cout << "class B : destructor" << endl;
    }
};

int main() {
    B b;
    A *a = &b, *c = new B();
    a->funcl();
    delete c;
    cout << "----------------" << endl;
    return 0;
}
