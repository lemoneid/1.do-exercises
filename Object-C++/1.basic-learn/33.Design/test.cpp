/*************************************************************************
	> File Name: 1.visitor.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 09时17分34秒
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


class A {
public :
    virtual ~A() {}
    virtual void run() {
        cout << "A run" << endl;
    }
};

class B : public A {
public :
    void run() {
        cout << "B run" << endl;
    }
    void say() {
        cout << "I am B" << endl;
    }

};
class C : public A {};
class D : public A {};
class E : public A {};

int main() {
    A *arr[10];

    A *temp = new B();
    cout << temp << endl;
    if (dynamic_cast<B *>(temp)) {
        cout << temp << endl;
        cout << dynamic_cast<B *>(temp) << endl;
        cout << "ok" << endl;
        dynamic_cast<B *>(temp)->say();
    }

    cout << "--------------------" << endl;

    for (int i  = 0; i < 10; ++i) {
        switch (rand() % 4) {
            case 0 : arr[i] = new B(); break;        
            case 1 : arr[i] = new C(); break;        
            case 2 : arr[i] = new D(); break;        
            case 3 : arr[i] = new E(); break;        
            default : arr[i] = new A(); break;
        }
    }

    //dynamic_cast : 还原原对象的地址,通过虚函数表地址判断,所以原有基类一定是抽象类(virtual)
    //有父类指针到子类指针根据不同类型做不同功能映射
    //如果少加一个派生类的条件分支if-else就会出错
    //visitor访问者模式,解决功能映射
    for (int i = 0; i < 10; ++i) {
        if(dynamic_cast<B *>(arr[i])) {
            cout << "this is a class B object" << endl;
        } else if (dynamic_cast<C *> (arr[i])) {
            cout << "this is a class C object" << endl;
        } else if (dynamic_cast<D *> (arr[i])) {
            cout << "this is a class D object" << endl;
        } else {
            cout << "this is a error class pointer" << endl;
        }
    }
    return 0;
}
