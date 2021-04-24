/*************************************************************************
	> File Name: 27.POD.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月21日 星期三 22时59分26秒
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
#include <type_traits>
using namespace std;

struct Trivial {
public :
    int a;
private :
    int b;
};

struct NoTrivial {
public :
    ~NoTrivial() {}
};


struct B1 { static int a; };
struct B2 { int a; };
struct D1 : B1 { int d; };               //1  
struct D2 : B2 { static int d; };        //1
struct D3 : B2, B1 { static int d;  };   //1
struct D4 : B2 { int d;  };              //0
struct D5 : B2, D1 {};                   //0 
//is_standard_layout<D1>::value
int main() {
    cout << is_trivial<Trivial>::value << endl;
    cout << is_trivial<NoTrivial>::value << endl;
    cout << "is_standard_layout" << endl;
    cout << is_standard_layout<D2>::value << endl; //1   
    cout << is_standard_layout<D3>::value << endl; //1   
    cout << is_standard_layout<D4>::value << endl; //0
    cout << is_standard_layout<D5>::value << endl; //0 

    return 0;
}
