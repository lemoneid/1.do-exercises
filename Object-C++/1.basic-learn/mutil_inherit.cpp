/*************************************************************************
	> File Name: mutil_inherit.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 19时47分17秒
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

struct Person {
    public:
    string lastName = ":";
    Person() = default;
    Person(string n) :lastName(n) {cout << "Person:"<< &lastName << endl;};
};

struct F :virtual Person {
    //string lastName = "y";
    F():Person("y") { cout << "F:" << &lastName << endl; };
};

struct M :virtual Person{
    //string lastName = "z";
    M():Person("z") {cout << "M:" << &lastName << endl;};
};

/*
    解决歧异性问题
        -1 指定访问的域
        -2 virtual 虚继承

        针对菱形继承，可以使用虚继承
            -1 此时无法在访问到基类（父类）对应的值
            -2 产生的对象的空间因此发生改变
                    Person  F    M   S1
    没有virtual     32      32  32  96
        Person:0x7ffdceacb130
        F:0x7ffdceacb130
        Person:0x7ffdceacb150
        M:0x7ffdceacb150
    加virtual后     32      40  40  80
        F:0x7ffefd729a40
        M:0x7ffefd729a40
    40 = 32 + 8
    80 = 40(Person) + 8(地址) +_ 32(myLastName)

    所谓的虚继承，产生的是一种地址拷贝，而不是空间拷贝
    来源于父母的空间，只有一份，这份是从祖先基类继承下来的，
    自然没有父母空间，也就无法访问；
    
    所有上层特性，其实到底层当中，都需要从内存角度思考
*/

struct S1: public F, public M {
    string myLastName; 
};

struct S2: S1 {
    string newLastName;
};

int main() {
    
    S1 s;
    cout << s.F::lastName << endl;
    cout << s.M::lastName << endl;
    cout << sizeof(Person) << " " << sizeof(F) << " " << sizeof(M) << " " << sizeof(S1) << endl;
    
    cout << sizeof(Person) << " " << sizeof(F) << " " << sizeof(M) << " " << sizeof(S2) << endl;
    return 0;
}
