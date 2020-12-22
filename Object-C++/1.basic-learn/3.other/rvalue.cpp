/*************************************************************************
	> File Name: rvalue.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 09时12分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;


void judge2(int &x) {
    cout << "int judge2 left value : " << x << endl;
    return ;
}

void judge2(int &&x) {
    cout << "int judge2 right value : " << x << endl;
    judge2(forward<int &>(x));
    return ;
}

void judge(int &x) {
    cout << "int judge1 left value : " << x << endl;
    judge2(x);
    return ;
}

void judge(int &&x) {
    cout << "in judge1 right value : " << x << endl;
    x = 123;
    judge2(forward<int &&>(x));
    return ;
}

class A {
public :  
    A (int n = 10) : arr(nullptr), n(n) {
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) {
            this->arr[i] = i;
        }
        cout << "constructor" << endl;
    }

    A(const A &obj) : arr(nullptr), n(obj.n) {
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) {
            this->arr[i] = obj.arr[i];
        }
        cout << "copy constructor" << endl;
        return ;
    }
    A(A &&obj) : arr(obj.arr), n(obj.n) {
        cout << "move constructor" << endl;
        obj.arr = nullptr;
        return ;
    }

    void output() {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ;
    }

    ~A() {
        delete[] arr;
        arr = nullptr;
        n = 0;
        cout << "destructor" << endl;
    }
private :
    int *arr, n;
};

int main() {
    constexpr int n = 2;
    //judge(n);
    //judge(move(n));
    judge(n);
    cout << n << endl;
    A *p = new A();
    A a = std::move(*p);
    delete p;
    a.output();

    return 0;
}
