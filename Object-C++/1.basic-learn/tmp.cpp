/*************************************************************************
	> File Name: tmp.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月28日 星期日 16时28分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>
using namespace std;
struct A
{
    int data;
    A(int theData)
    :data{ theData }
    {
    }
};
struct B : virtual A
{
    B() :A{ 1 }
    {
        cout << "B " << data << endl;
    }
};
struct C : virtual A
{
    C() :A{ 2 }
    {
        cout << "C : " << data << endl;
    }
};
struct D : B, C
{
    D() : A {3} {
        
    }
};
int main() {
    D d;
    cout << d.data << endl;
}
