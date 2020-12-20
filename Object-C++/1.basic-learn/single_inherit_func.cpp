/*************************************************************************
	> File Name: single_inherit_func.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 19时06分22秒
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

class Person {
    string name;
public:
    Person(string n) {
        name = n;
    }
    void showMessage() {
        cout << name << endl;
    }
};

/*
    继承的类， 对于父类当中成员函数
    系统会隐式调用其默认的构造函数
    如果没有，必须显示调用-->成员初始化列表
*/
class Man : Person {
    string workName;
public:
    Man(string n, string work) : Person(n) {
        workName = work;
    }

    Man(const Man &m): Person(m) {
        cout << "--default--" << endl;
        this->workName = m.workName;
    }
    Man &operator=(const Man &m) :Person(m) {
        cout << "--operator=--" << endl;
        this->workName = m.workName;
    }
    void showMessagePerson() {
        this->showMessage();
    }
    void showMessageMan() {
        cout << workName << endl;
    }
};

int main() {
    Man m = Man("worst", "coder"); 
    m.showMessagePerson();
    m.showMessageMan();
    Man newm = m;
    newm.showMessagePerson();
    newm.showMessageMan();
    return 0;
}
