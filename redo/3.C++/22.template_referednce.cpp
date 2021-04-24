/*************************************************************************
	> File Name: 22.template_referednce.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月19日 星期一 21时20分28秒
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

#define END }
#define BEGIN(name )namespace name {

BEGIN(worst)
template<typename T>
void swap(T &&a, T &&b) { //&&表示传引用：左值和右值引用; &表示左值引用
    //T c = a; //error 引用折叠
    //去除引用
    typename remove_reference<T>::type c;
    c = a; 
    a = b; b = c;
    return ;
}

END


int main() {
    int n = 123, m = 456;
    worst::swap(n, m);
    return 0;
}
