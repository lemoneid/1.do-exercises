/*************************************************************************
	> File Name: 12.virtual.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月16日 星期三 10时20分38秒
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

string rand_name(int n) {
    string name = "";
    for (int i = 0; i < n; ++i) {
        name = name + (char)(rand() % 26 + 'A');
    }
    return name;
}

class Animal {
public : 
    Animal(string name) : name(name) {};
    string tell_name() {
        return this->name;
    }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
private : 
    string name;
    
};

class Cat : public Animal {
public : 
    Cat() : Animal(rand_name(5) + " Cat") {
    }
    void run() {
        cout << "I can run with four legs" << endl;
    }
    void say() {
        cout << "miao~ miao~ miao~" << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

class Bat: public Animal {
public : 
    Bat() : Animal(rand_name(5) + " Bat") {}
    void run() {
        cout << "I can fly" << endl;
    }
    void say() {
        cout << "si~ si~ si~" << endl;
    }
    ~Bat() {
        cout << "Bat destructor" << endl;
    }
};

class test : public Cat {
    void run() {
        cout << " test run" << endl;
    }
};

int main() {
    Cat a;
    Bat b;
    cout << a.tell_name() << endl;
    a.run();
    cout << b.tell_name() << endl;
    b.run();
    Animal **arr = new Animal*[10];
    for (int i = 0; i < 10; ++i) {
        if (rand() % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i]->tell_name() << endl;
        arr[i]->run();
    }
    for (int i  = 0; i < 10; ++i) {
        delete arr[i];
    }
    delete[] arr;
    Animal *p = new test;
    p->run();
    return 0;
}
