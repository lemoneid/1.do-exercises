/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 11时17分03秒
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

void func(int *b) {
    cout << "b : " << sizeof(b) << endl;
}

class Data {

};

class Y {
protected :
    int member;
    char *data;
public :
    Y() {
       data = new char[10]; 
    }
//private :
    virtual ~Y() {
        cout << "Y destructor" << endl;
    }
};

class X : public Y {
public :
    void Method(X &y) {
        &y.member;
        //&(static_cast<Y&>(y).member);
    }
    ~X() {
        cout << "X destructor" << endl;
    }
};


int main() {
    Y *obj = new X[10];
    delete[] obj;
    cout << "-----------" << endl;
    cout << typeid(nullptr).name() << endl;
    cout << typeid(void *).name() << endl;
    cout << sizeof(Data) << endl;
    cout << "-------------" << endl;
    int a[100];
    cout << "a : " << sizeof(a) << endl;
    cout << "&a : " << sizeof(&a) << endl;
    cout << "a[100] : " << sizeof(a[100]) << endl;
    cout << "&a[0] : " << sizeof(&a[0]) << endl;
    cout << a << endl;
    cout << &a << endl;
    cout << a + 1 << endl;
    int b = 0, c =  1;
    func(a);
};


