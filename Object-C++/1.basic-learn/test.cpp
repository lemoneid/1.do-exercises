/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 11时17分03秒
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

void func(int *b) {
    cout << "b : " << sizeof(b) << endl;
}

class Data {

};

int main() {

    cout << sizeof(Data) << endl;
    cout << "-------------" << endl;
    int a[100];
    cout << "a : " << sizeof(a) << endl;
    cout << "&a : " << sizeof(&a) << endl;
    cout << "a[100] : " << sizeof(a[100]) << endl;
    cout << "&a[0] : " << sizeof(&a[0]) << endl;
    cout << a << endl;
    cout << &a << endl;
    cout << a + 1 << endl;
    int b = 0, c =  1;
    func(a);
};


