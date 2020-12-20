/*************************************************************************
	> File Name: constructor.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 10时42分25秒
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

class Person
{
private:
    string name;
    unsigned int IDNumber;
public:
    Person ()
    {
        cout << "构造函数" << endl;
    }

    Person (string n)
    {
        name = n;
        cout << "构造函数for name" << endl;
    }

    Person (const char * n)
    {
        name = n;
        cout << "构造函数 use char *" << endl;
    }

    // 如果不想隐式调用单参数构造函数
    // explicit对于单参数构造函数 必须显示调用
    explicit Person (unsigned int idn)
    {
        IDNumber = idn;
        cout << "构造函数 for IDNumber" << endl;
    }

    Person (string n, unsigned int idn)
    {
        name = n;
        IDNumber = idn;
        cout << "构造函数 for name&IDNumber" << endl;
    }
};

struct SomeBody
{
private:
    const string name;
    const unsigned int IDNumber;
public:
    // 如果类当中存在const的成员变量 
    // 需要使用初始化成员列表方式
    SomeBody(string n, unsigned int idn):name(n),IDNumber(idn)
    {
        // name = n;
        // IDNumber = idn;
    }
};

/*
    对象构造
    生成对象所需要调用的方法——》构造函数
    系统自动合成了默认构造函数
*/

int main()
{
    Person p; //类似于变量的栈区隐式调用构造
    // Person p1();// 这种方式会将p1当成一种函数调用
    Person p2 = Person();

    Person *p3 = new Person;
    Person *p4 = new Person();

    Person p5 = Person(1002); // 调用对应的构造函数进行对象构造
    // Person p6 = Person("张三");
    Person p6 = string("张三");
    Person p7{"李四", 1003};

    Person p8 = "赵柳";

    string str = "王五";// 这句话为什么不报错？
    /*
        C++11就地初始化的限制条件
        （1）需要初始化的数据为公有性访问
        （2）不要显式定义默认的构造函数
        TIPS：上述两点在于保证其就地初始化的“数据性”
        （3）定义与其匹配的构造函数
    */
    SomeBody sb{"张三", 1001};



    return 0;
}
