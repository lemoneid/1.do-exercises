/*************************************************************************
	> File Name: friend.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 11时47分33秒
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
#include <string>
using namespace std;

/*
    (1) 友元关系不能被继承。 
    (2) 友元关系是单向的，不具有交换性。
    若类B是类A的友元，类A不一定是类B的友元，
    要看在类中是否有相应的声明。
    (3) 友元关系不具有传递性。若类B是类A的友元，
    类C是B的友元，类C不一定是类A的友元，
    同样要看类中是否有相应的申明
*/

/*
    正常对于某个私有成员，设置set/get方法
*/

class SomeBody
{
    string name;
public:
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    // 友元的作用，使外部也可以访问私有成员
    // 声明友元函数
    friend void showMe(SomeBody &);

    // 声明为友元类 友元类里的 \
    所有成员函数都可以访问被友元的类的私有变量
    friend class Friend;
};

void showMe(SomeBody &sb)
{
    cout << sb.name << endl;
}

class Friend
{
public:
    void showMyFriend(SomeBody &sb)
    {
        cout << sb.name << endl;
    }
};

int main()
{
    SomeBody sb;
    sb.setName("傻傻的小可爱");

    // sb.name = "";

    cout << sb.getName() << endl;

    showMe(sb);

    Friend().showMyFriend(sb);

    return 0;
}
