/*************************************************************************
	> File Name: copy_assign.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月20日 星期五 18时10分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
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

class PersonInfo
{
    string address = "中国浙江省杭州市余杭区";
    // 这个数据类成员的一部分, 而不是对象
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
