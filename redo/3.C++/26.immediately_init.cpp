/*************************************************************************
	> File Name: 26.immediately_init.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月21日 星期三 21时27分52秒
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
using namespace std;

struct A {
    A(int i) : val(i) {}
    int val;
};

struct init {
    
    A x = 1; //ok
    A z{1}; // ok
    A y(1); // not allow 
    string b("hello"); // not allow
};

int main() {


    return 0;
}
