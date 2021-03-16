/*************************************************************************
	> File Name: 5.virtual_table.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 19时01分55秒
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


class Animal {
public :
    Animal() {
        x = 8827, y = 65123;
    }
    virtual void say(int x) {
        cout << "I don't know how to say" << endl;
    }
    virtual void run() = 0;
protected :
    int x, y;
};

class Cat : public Animal {
public :
    void say(int x) override {
        cout << this << endl;
        cout << this->x << " " << this->y << endl;
        cout << x << endl;
        cout << "miao~miao~miao" << endl;
    }
    virtual void run() final {
        cout << "I can run"  << endl;
    }
};

void output_raw_data(void *q, int n) {
    printf("%p : ", q);
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < n; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
    return ;
}

typedef void(*func)(void *, int x);

int main() {

    Cat a, b;
    output_raw_data(&a, sizeof(a));
    output_raw_data(&b, sizeof(b));
    ((func **)(&a))[0][0](&a, 213123);
    ((func **)(&b))[0][0](&b, 123);
    return 0;
}
