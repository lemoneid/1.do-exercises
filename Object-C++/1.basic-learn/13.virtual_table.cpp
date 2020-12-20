/*************************************************************************
	> File Name: 13.virtual_table.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月16日 星期三 12时42分07秒
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
#include <functional>
using namespace std;

class Animal {
public : 
    Animal() {
        x = 123131, y = 348123;
    }
    virtual void say(int x) {
        cout << this << endl;
        cout << x << endl;
        cout << "I don't know how to say" << endl;
    }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
protected : 
    int x, y;
};

class Cat : public Animal {
public : 
    void say(int x) override {
        cout << this << endl;
        cout << this->x << " " << this->y << endl;
        cout << "miao~ miao~ miao~" << endl;
    }
    void run() override {
        cout << "I can run with four leg" << endl;
    }
    virtual void hear() {
        cout << "I can hear with my ears" << endl;
    }
private :
};

void output_raw_data(void *q, int size) {
    cout << "address :" << q << " ";
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < size; ++i) {
        printf("%02X ", p[i]);
    }
    cout << endl;
    return ;
}

typedef void(*func)(void *, int); 
typedef void(*func1)(void *); 

int main() {
    Cat a, b, c;
    output_raw_data(&a, sizeof(a));
    output_raw_data(&b, sizeof(b));
    output_raw_data(&c, sizeof(c));
    ((func **)(&a))[0][0](&a, 23);
    ((func1 **)(&a))[0][1](&a);
    ((func1 **)(&a))[0][2](&a);
    return 0;
}
