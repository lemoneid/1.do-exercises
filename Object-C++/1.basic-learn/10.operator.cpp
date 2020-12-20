/*************************************************************************
	> File Name: 10.operator.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月15日 星期二 20时25分55秒
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

struct Point {
    Point() { cout << "default constructor" << endl; }
    Point(int x, int y) : x(x), y(y) { cout << "argu constructor" << endl; }
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "copy constructor" << this <<  endl;
    }
    int operator()(int num) {
        return this->x + this->y + num;
    }
    int operator[](string str) {
        if (str == "x") return this->x;
        if (str == "y") return this->y;
    }
    Point operator-(const Point &a) {
        Point ret;
        ret.x = this->x - a.x;
        ret.x = this->y - a.y;
    }
    ~Point() {
        cout << "dest" << endl;
    }
    friend Point operator+(const Point &, const Point &);
private:
    int x, y;
};

Point operator+(const Point &a, const Point &b) {
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
}

int main() {
    Point a(2, 4), b(5, 4);
    Point c = a + b;
    Point d = a + b + c;
    cout << a(5) << endl;;
    cout << a["x"] << a["y"] << endl;
    return 0;
}
