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

typedef unsigned int uInt;

class PersonInfo
{
    string name;
    uInt IDNumber;
    string address;
    string company;
    bool isMale;
public:
    //PersonInfo(){};  PersonInfo() = default; ???

    PersonInfo(){};
    PersonInfo(uInt idn) {
        IDNumber = idn;
    }

    //PersonInfo(const PersonInfo &pi) = delete;
    //系统的拷贝构造函数和构造函数不同，该函数不可重载
    
    PersonInfo(const PersonInfo &pi) {
        cout << "默认copy" << endl;
        address = pi.address;
        company = pi.company;
        isMale = pi.isMale;
    }
    //赋值操作运算符重载函数，其default和delete型和拷贝函数一致
    PersonInfo& operator=(const PersonInfo &pi) {
        cout << "重载=" << endl;
        address = pi.address;
        company = pi.company;
        isMale = pi.isMale;
        return *this;
    }

    //为什么不可用default，可用delete；
    void displayInfo(PersonInfo &info) {
        cout << info.name << endl;
        cout << info.IDNumber<< endl;
        cout << info.address << endl;
        cout << info.company << endl;
    }

    PersonInfo makeCopy(const PersonInfo &pi) {
        PersonInfo temp;
        temp.name = pi.name;
        temp.IDNumber = pi.IDNumber;
        return temp;
    }

};

int main()
{
    PersonInfo pi(1);
    pi.displayInfo(pi);
    PersonInfo pj = pi;
    pj.displayInfo(pj);
    PersonInfo pt = pi;
    pt.displayInfo(pt);
    return 0;
}
