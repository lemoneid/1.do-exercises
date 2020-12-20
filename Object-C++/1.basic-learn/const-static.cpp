/*************************************************************************
	> File Name: const-static.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 11时48分44秒
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
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

/*
    static 修饰的是类成员函数和成员变量——封装性对其仍有作用
    所有的对象拿到的都是同一份类成员变量
    类成员函数可以使用普通对象调用，也可以使用类调用
*/

/*
    const 对象只能调用const函数
    非const对象即能调用非const也能调用const

    const成员变量初始化必须使用初始化列表
    const成员函数里不可修改成员变量的值
    如果成员变量定义前加了mutable，表示成员可以在const成员函数里修改

    在部分场景下，需要定义const版本和非const两个版本的函数
*/

/*
部分运算符重载
	可重载运算符
		双目算术运算符	+ (加)，-(减)，*(乘)，/(除)，% (取模)
关系运算符	==(等于)，!= (不等于)，< (小于)，> (大于>，<=(小于等于)，>=(大于等于)
逻辑运算符	||(逻辑或)，&&(逻辑与)，!(逻辑非)
单目运算符	+ (正)，-(负)，*(指针)，&(取地址)
自增自减运算符	++(自增)，--(自减)
位运算符	| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
赋值运算符	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
空间申请与释放	new, delete, new[ ] , delete[]
其他运算符	()(函数调用)，->(成员访问)，,(逗号)，[](下标)
	
    不可重载运算符
		.：成员访问运算符
.*, ->*：成员指针访问运算符
::：域运算符
sizeof：长度运算符
?:：条件运算符
#： 预处理符号
	
    重载规则
		（1）不可臆造运算符；
（2）运算符原有操作数的个数、优先级和结合性不能改变；
（3）操作数中至少一个是自定义类型；
（4）保持重载运算符的自然含义。
		（1）当重载为成员函数时，会隐含一个this指针；当重载为友元函数时，不存在隐含的this指针，需要在参数列表中显示地添加操作数。
（2）当重载为成员函数时，只允许右参数的隐式转换；当重载为友元函数时，能够接受左参数和右参数的隐式转换。
		一般规则为：单目成员，双目友元
		=、()、[]、以及 ->操作符只能被类的成员函数重载
		<< >>定义为友元
*/


/*
三（拷贝构造，拷贝赋值运算符，析构函数）五法则
	需要析构函数的类也需要拷贝构造函数和拷贝赋值函数。
	需要拷贝操作的类也需要赋值操作，反之亦然。
	析构函数不能是删除的
	如果一个类成员有删除的或不可访问的析构函数，那么其默认和拷贝构造函数会被定义为删除的。
	如果一个类有const或引用成员，则不能使用合成的拷贝赋值操作。（无法默认构造的const成员的类 则该类就无默认构造函数）
*/

class PersonInfo
{
    string address = "中国浙江省杭州市余杭区";
    // 这个数据类成员的一部分
    static string name;
    bool isMale = true;

    mutable int number;
public:
    void displayInfo() const
    {
        cout << address << endl;
        cout << name << endl;

        // address = "中国上海市虹桥区虹桥机场";
        // number = 10001;
    }

    void displayInfo()
    {
        cout << address << endl;
        cout << name << endl;
        cout << "this is non const version" << endl;

        // address = "中国上海市虹桥区虹桥机场";
        // number = 10001;
    }

    static void displayInfo(const PersonInfo &info)
    {
        cout << info.address << endl;
        cout << info.name << endl;
    }

    void changeIsMale()
    {
        isMale = !isMale;
    }
};

string PersonInfo::name = "李四";

void displayInfo(const PersonInfo &info)
{
    info.displayInfo();
}

int main()
{
    PersonInfo pi;
    PersonInfo *somePs = new PersonInfo[100]; 
    pi.displayInfo();

    displayInfo(somePs[10]);

    // PersonInfo::name = "王五";

    pi.displayInfo(somePs[66]);

    PersonInfo::displayInfo(somePs[77]);

    pi.changeIsMale();
    return 0;
}
