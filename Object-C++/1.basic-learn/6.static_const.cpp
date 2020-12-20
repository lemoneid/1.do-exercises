/*************************************************************************
	> File Name: 6.static_const.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月14日 星期一 19时14分04秒
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

class T {
public :
    T() {cout << "T constructor" << endl;}; 
    ~T() {cout << "T destroy" << endl;}; 
private:
};

class Point {
public :
    Point();
    Point (int x, int y);
    int x() const;
    int y() const;
    int x_cnt() const; 
    void set_x(int x);
    void set_y(int y);
    static void output_cnt();
    ~Point();
private :
    int __x, __y;
    static int point_cnt;
    T a;
    mutable int __x_cnt;
};

Point::Point() : __x_cnt(0) {
    Point::point_cnt++;
    cout << "Point constructor" << endl;
}
Point::Point(int x, int y) : __x(x), __y(y), __x_cnt(0) { 
    Point::point_cnt++;
    cout << "Point constructor" << endl;
}
Point::~Point() {
    Point::point_cnt--;
    cout << "Point destroy" << endl;
}

int Point::point_cnt = 0;
void Point::output_cnt() {
    cout << Point::point_cnt;
}
int Point::x_cnt() const {
    return this->__x_cnt;
}

int Point::x() const {
    return this->__x;
}
int Point::y() const {
    return this->__y;
}

void Point::set_x(int x) {
    this->__x_cnt++;
    this->__x = x;
}

void Point::set_y(int y) {
    this->__y = y;
}

int main() {
    {
        Point a(2, 3);
        Point *p = &a;
        //const Point c(4, 5);
        Point::output_cnt();
    }
    return 0;
}
