/*************************************************************************
	> File Name: vfptr.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月07日 星期一 10时59分32秒
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
class Base1
{
public:
    int base1_1;
    int base1_2;

    virtual void base1_fun1() { cout << "base fun1" << endl;}
    virtual void base1_fun2() { cout << "base fun2"  << endl;}
};

class Derive1 : public Base1
{
public:
    int derive1_1;
    int derive1_2;

    // 覆盖基类函数
    virtual void base1_fun1() { cout << "derive fun1" << endl;}
};
int main() {
    Base1 *p = nullptr;
    Derive1 d1;
    Base1 b1;
    p = &d1;
    p->base1_fun1();
    p->base1_fun2();
    p = &b1;
    p->base1_fun1();
    p->base1_fun2();
    cout << sizeof(Base1) << " " << sizeof(Derive1) << endl;
    return 0;
}
