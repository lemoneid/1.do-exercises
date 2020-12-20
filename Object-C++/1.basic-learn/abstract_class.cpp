/*************************************************************************
	> File Name: abstract_class.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 21时11分38秒
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

/*
    拥有纯虚函数的类，称为抽象类
    抽象类不可以构造对象
    
    派生类没有对纯虚函数进行实现，那么派生类也是抽象类

    和泛化关系的区别在于，泛化的类可以生产对象
    WorkBuilding 与 Building 之间就是实现关系

    C++当中面向接口编程，就是通过抽象类实现的
    比如：娃哈哈就是一个借口，抽象
        矿泉水
        营养快线

    工厂设计模式
        实际由该工厂生产对象
    抽象工厂设计模式
        只提供生产技术支持，平台授权等 Apple
*/

class Building {
    public:
    virtual void build() = 0;
};

class WorkBuilding : public Building {
    public:
    void build() {
        cout << "建造" << endl;
    }   
};

int main() {
    Building *someBuild = new WorkBuilding;
    someBuild->build();
    return 0;
}
