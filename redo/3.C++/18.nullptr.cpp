/*************************************************************************
	> File Name: 18.nullptr.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月18日 星期日 22时37分32秒
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

/*
void func(double x) {
    cout << "int " << x << endl;
}
*/

void func(int *x) {
    cout << " * int *" << x << endl;
}

int main() {
    cout << NULL << endl;
    //cout << nullptr << endl;
    if (NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if (nullptr) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    func(nullptr);
    func(NULL);
    cout << (typeid(long ).hash_code() == typeid(NULL).hash_code()) << endl;
    cout << typeid(int).name() << endl;
    cout << typeid(long ).name() << endl;
    cout << typeid(NULL).name() << endl;
    cout << typeid(nullptr).name() << endl;
    func(0);
    return 0;
}
