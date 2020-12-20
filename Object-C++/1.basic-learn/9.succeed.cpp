/*************************************************************************
	> File Name: 9.succeed.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月14日 星期一 21时22分24秒
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

#define P_ADD(obj, a) out << #obj "." #a " = " << &(obj.a)

class Animal {
public : 
    string name() { return this->__name; }
    Animal(string name) : __name(name) {
        cout << "Animal constructor " << this << endl;
    } 
    int x, y;
    string __name;
    ~Animal() {
        cout << "Animal destructor " << this << endl;
    }
};

class Cat : public Animal {
public :
    Cat() : Animal("hello kitty") {
        cout << "Cat constructor " << this <<endl;
    }
    void say() {
        cout << "my name is " << this->name() << endl;
    }
    int z;
    ~Cat() {
        cout << "Cat destructor " << this << endl;
    }
};
ostream &operator<<(ostream &out, const Animal &obj) {
    out << "<class Animal> " << &obj << endl;
    return out;
}

ostream &operator<<(ostream &out, const Cat &obj) {
    out << "<class Cat> " << &obj << endl;
    P_ADD(obj, x) << endl;
    P_ADD(obj, y) << endl;
    P_ADD(obj, __name) << endl;
    P_ADD(obj, z) << endl;
}

int main() {
    Animal *p = new Cat(); 
    Cat a;
    a.say();
    cout << a << endl;
    cout << "Animal *" << p->name() << endl;
    cout << endl << endl;
    Animal &q = a;
    cout << q;
    delete p;
    return 0;
}
