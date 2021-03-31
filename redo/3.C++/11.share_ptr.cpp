/*************************************************************************
	> File Name: 11.share_ptr.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月29日 星期一 14时38分49秒
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

namespace test {

class A {
public :
    A() {
        cout << "constructor" << endl;
    }
    ~A() {
        cout << "delstructor" << endl;
    }
    friend ostream& operator<<(ostream &out, const A &obj) {
        out << "hello";
        return out;
    }
};

class shared_ptr {
public :
    shared_ptr();
    shared_ptr(A *);
    shared_ptr(const shared_ptr &);
    ~shared_ptr();
private :
    int *cnt;
    A *obj;
};

shared_ptr::shared_ptr() : obj(nullptr), cnt(nullptr) {}
shared_ptr::shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {};
shared_ptr::shared_ptr(const shared_ptr &p) : obj(p.obj), cnt(p.cnt) { *p.cnt += 1; }
shared_ptr::~shared_ptr() {
    if (cnt != nullptr) {
        *cnt -= 1;
        if (*cnt == 0) delete obj;
        obj = nullptr;
        cnt = nullptr;
    }
    
}
}

int main() {
    test::A *p1 = new test::A();
    p1 = nullptr;
    test::shared_ptr p2(new test::A());
    cout << test::A() << endl;
    return 0;
}
