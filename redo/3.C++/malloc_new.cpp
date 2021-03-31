/*************************************************************************
	> File Name: malloc_new.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月29日 星期一 13时29分42秒
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
    A() {
        cout << "A default constructor" << endl;
    }
    A(int x) {

    }
    ~A() {
        cout << "delstructor A" << endl;
    }
};

struct B {
    B() {
        cout << "B default constructor" << endl;
    }
    ~B() {
        cout << "B delstructor" << endl;
    }
};



int main() {
    int n = 5;
    cout << "malloc A" << endl;
    A *arr1 = (A *)malloc(sizeof(A) * n);
    for (int i = 0; i < n; i++) {
        new (arr1 + i) A();
    }
    delete arr1;
    free(arr1);
    cout << "new A" << endl;
    A *arr2 = new A[n];
    delete[] arr2;
    return 0;
}
