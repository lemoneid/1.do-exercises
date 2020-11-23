#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

/*
    修改拷贝值是否会更改原值
    是：浅
    否：深

    业务逻辑层，根据需要，如果是拷贝构造，会定义成深拷贝

    浅拷贝，不要创建对象，只做指针的引用
*/
class Address
{
public:
    string city;
};

class PersonInfo
{
    
public:
    Address *myAddress;
    PersonInfo() {
        myAddress = new Address;
    };
    // 这是？深拷贝
    PersonInfo(const PersonInfo &info)
    {
        //myAddress = new Address; 
        myAddress->city = info.myAddress->city;
    }

    ~PersonInfo()
    {
        delete myAddress;
    }
};

int main()
{
    // 此时发生的是深拷贝还是浅拷贝  深拷贝
    int n = 10;
    int m = n;

    // 那现在呢 浅拷贝
    int &k = n;
    int *p = &n;
    *p = 100;

    cout << k << endl;
    // 对于指针来说，这是一种浅拷贝
    int *pp = p;

    *pp = 666;

    cout <<  k << endl;

    // 这里就是深拷贝的策略
    int *ppp = (int *)malloc(4);
    *ppp = *p;
    *ppp = 888;

    cout <<  k << endl;

    // 这里是深拷贝
    vector<int> coll;
    coll.push_back(k);
    PersonInfo p1;
    p1.myAddress->city = "杭州";
    cout << "test"<< endl;
    PersonInfo p2 = p1;
    cout << "test"<< endl;

    p2.myAddress->city = "株洲";

    cout << p1.myAddress->city << endl;

    return 0;
}
