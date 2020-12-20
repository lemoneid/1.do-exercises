/*************************************************************************
	> File Name: dynamic_condi.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 20时46分03秒
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

struct Animal {
    virtual void eat() {
        cout << "Animal eat something" << endl;
    }
};

struct Dog: Animal {
    void eat() {
        cout << "Dog eat meat" << endl;
    }
};

struct Cat: Animal {
    void eat() {
        cout << "Cat eat fish" << endl;
    }
};
struct Mouse: Animal {
    void eat() {
        cout << "Mouse eat nailao" << endl;
    }
};

/*
    动态多态发生的条件
        -1 必须有继承
        -2 必须有方法重写
        -3 基类的指针或引用绑定子类的对象
        -4 发生多态的函数必须为虚函数


    
    当一个类中，没有设置一个函数为虚函数时，
    程序在编译期间会生成该函数的静态地址，
    通过对象指针，可以访问到改地址，也就没有segmentation fault 

    设置一个函数为虚函数后
    对象空间中就一个虚函数表，如果一个对象搜索不到该虚函数表，
    产生segmentation fault
    
    动态绑定用于传递结果

*/

/*
void lockSick(SomePerson *) {
    
}
*/

int main() {
    //tom and jerry 
    Dog spike;
    Cat tom;
    Mouse jerry;
    //why 空指针可以调用eat方法；
    Animal *anyAnimal = nullptr;
    //anyAnimal->eat();

    cout << sizeof(*anyAnimal) << endl;

    anyAnimal = &spike;
    anyAnimal->eat();

    anyAnimal = &tom;
    anyAnimal->eat();

    anyAnimal = &jerry;
    anyAnimal->eat();
    return 0;
}
