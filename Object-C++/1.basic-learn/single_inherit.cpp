/*************************************************************************
	> File Name: single_inherit.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 18时28分17秒
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
    成员变量基类当中封装 private protected public
    
    继承封装
    private     本类当中可以访问，派生类不可访问
    protected   public降为protected
    public      不更改任何权限

    继承只能缩减封装，不能扩充封装权限
    继承的限制是影响下一代的
    如果没有后继类，可以设置为private私有继承
    如果不希望更改任何原先的成员权限，可以设置为public
    如果希望数据对外部保护，内部公开，设置为protected


*/
class Base {
private:
    int n = 10;
protected:
    int j = 100;
public:
    int m = 666;
};

class Drived : protected Base {
// private:
//   对于private继承派生类： 其父类的protected ，public j, m 相当于放在当前private下

public:
    void showMessage() {
        cout << j << endl;
        cout << m << endl;
    }
};

class Third : Drived{
public:
    void showMessageTT() {
        cout << j << endl;
        cout << m << endl;
    }

};


int main() {
    Drived d;
    d.showMessage();
    Third s;
    s.showMessageTT();
    return 0;
}
