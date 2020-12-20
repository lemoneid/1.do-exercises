/*************************************************************************
	> File Name: overload_operator.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 12时01分04秒
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
public: 
    string name;
    
    Person operator+(const Person &p1) {
        cout << p1.name << " + " << name << endl;
        Person newPerson;
        return newPerson;
    }
    Person &operator++() {
        cout << this->name << " just keep" << endl;
        return *this;
    }
    // 自增运算符有两个版本
    // 后置++，当中int是一个哑元
    // 哑元：重载发生。参数的个数不同，类型不同；
    Person &operator++(int x) {
        cout << this->name << "x just keep" << endl;
        cout << x << endl;
        return *this;
    }

};

int main() {
    Person man;
    man.name = "past";
    Person woman;
    woman.name = "persent";

    Person newPerson =  man + woman;
    newPerson.name = "future";
    Person p1;
    p1.name = "p1";
    p1.operator++();
    ++p1;
    p1++;
    p1.operator++(111);
    return 0;
}
