/*************************************************************************
	> File Name: visitro.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 09时37分27秒
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


class DeriveA;
class DeriveB;
class DeriveC;
class DeriveD;

class Base {
public :
    class Visitor {
    public : 
        virtual void visit(DeriveA *) = 0;
        virtual void visit(DeriveB *) = 0;
        virtual void visit(DeriveC *) = 0;
        virtual void visit(DeriveD *) = 0;
    };
    virtual void Accept(Visitor *vis) = 0;
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class DeriveA : public Base {
public :
    void Accept(Base::Visitor *vis) {
        return vis->visit(this);
    }
    ~DeriveA() {
        cout << "DeriveA destructor" << endl;
    }
};

class DeriveB : public Base {
public :
    void Accept(Base::Visitor *vis) {
        return vis->visit(this);
    }
    ~DeriveB() {
        cout << "DeriveB destructor" << endl;
    }
};
class DeriveC : public Base {
public :
    void Accept(Base::Visitor *vis) {
        return vis->visit(this);
    }
    ~DeriveC() {
        cout << "DeriveC destructor" << endl;
    }
};
class DeriveD : public Base {
public :
    void Accept(Base::Visitor *vis) {
        return vis->visit(this);
    }
    ~DeriveD() {
        cout << "DeriveD destructor" << endl;
    }
};
class OutputVisitor : public Base::Visitor {
    void visit(DeriveA *obj) {
        cout << "this is a A object" << endl;
    }
    void visit(DeriveB *obj) {
        cout << "this is a B object" << endl;
    }
    void visit(DeriveC *obj) {
        cout << "this is a C object" << endl;
    }
    void visit(DeriveD *obj) {
        cout << "this is a D object" << endl;
    }
};



int main() {
    srand(time(0));
    Base *arr[10];
    for (int i = 0; i < 10; ++i) {
        switch (rand() % 4) {
            case 0 : arr[i] = new DeriveA(); break;
            case 1 : arr[i] = new DeriveB(); break;
            case 2 : arr[i] = new DeriveC(); break;
            case 3 : arr[i] = new DeriveD(); break;
        }
    }
    OutputVisitor vis;
    for (int i = 0; i < 10; ++i) {
        arr[i]->Accept(&vis);
    }

    for (int i = 0; i < 10; ++i) {
        delete arr[i];
    }

    return 0;
}
