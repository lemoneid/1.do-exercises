/*************************************************************************
	> File Name: mutil_condi.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 20时33分49秒
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

void swap(int a, int b) { cout << "int" << endl; };
void swap(string a, string b) { cout << "string" << endl; };
void swap(double a, double b) { cout << "double" << endl; };
void swap(char a, char b) {cout << "char" << endl;};

/*
    静态多态
    必须在编译器期给定类型>对应的数据类型

    指针包含多层含义
        -1 空间地址
        -2 空间长度
        -3 从空间读取出的值的类型

    编译期已经确定其寻址方式

*/

int main() {
    int *i, *j;
    i = (int *)malloc(3);
    j = (int *)malloc(3);
    cout << sizeof(*i) << endl;
    swap(*i, *j);

    return 0;
}
