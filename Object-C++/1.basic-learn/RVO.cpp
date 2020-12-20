/*************************************************************************
	> File Name: RVO.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月14日 星期一 20时10分39秒
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

class A {
public :
    A() {
        cout << "constructor" << endl;
    }
    A(const A &obj) {
        cout << "copy constructor" << endl;
    } 
};

A func() {
    A temp;
    return temp;
}

int main() {
    A tmp = func();

    return 0;
}
