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
class B;
class C;
class D;
class E;
class F;

class A {
public :
    class IVisitor {
    public : 
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
    };
    //virtual void Accept(IVisitor *) = 0;
    virtual void Accept(IVisitor *vis) {
           vis->visit(this); 
    }
    virtual ~A() {}
};

class B : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class C : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class D : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class E : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class F : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor {
    virtual void visit(A *obj) {
        cout << "this is a class A father" << endl;
    }
    virtual void visit(B *obj) {
        cout << "this is a class B object" << endl;
    }
    virtual void visit(C *obj)  {
        cout << "this is a class C object" << endl;
    }
    virtual void visit(D *obj) {
        cout << "this is a class D object" << endl;
    }
    virtual void visit(E *obj) {
        cout << "this is a class E object" << endl;
    }
    virtual void visit(F *obj) {
        cout << "this is a class E object" << endl;
    }
};

class CalcVisitor : public A::IVisitor {
    virtual void visit(A *obj) {
        cout << ans << endl;
    }
    virtual void visit(B *obj) {
        ans += 5;
        cout << "+5 : " << " " << ans << endl;
    }
    virtual void visit(C *obj)  {
        ans *= 2;
        cout << "*2 : " << " " << ans << endl;
    }
    virtual void visit(D *obj) {
        ans -= 4;
        cout << "-4 : " << " " << ans << endl;
    }
    virtual void visit(E *obj) {
        ans += 6;
        cout << "+6 : " << " " << ans << endl;
    }
    virtual void visit(F *obj) {
        ans -= 7;
        cout << "-7 : " << " " << ans << endl;
    }
public :
    //static int ans;
    CalcVisitor(int ans = 1) : ans(ans) {}
    int ans;
};

//int CalcVisitor::ans = 0;


int main() {
    A *arr[10];
    for (int i  = 0; i < 10; ++i) {
        switch (rand() % 4) {
            case 0 : arr[i] = new B(); break;        
            case 1 : arr[i] = new C(); break;        
            case 2 : arr[i] = new D(); break;        
            case 3 : arr[i] = new E(); break;        
        }
    }

    //dynamic_cast : 还原原对象的地址,通过虚函数表地址判断,所以原有基类一定是抽象类(virtual)
    //有父类指针到子类指针根据不同类型做不同功能映射
    //如果少加一个派生类的条件分支if-else就会出错
    //visitor访问者模式,解决功能映射
    OutputVisitor vis1;
    CalcVisitor vis2;
    for (int i = 0; i < 10; ++i) {
        arr[i]->Accept(&vis1);
        arr[i]->Accept(&vis2);
    }
//    cout << CalcVisitor::ans << endl;
    cout << vis2.ans << endl;
    return 0;
}
