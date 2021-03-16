/*************************************************************************
	> File Name: 3.operator.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 17时11分20秒
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

class Point {
public :
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {}
    int operator()(int num) {
       return x + y + num; 
    }
    Point operator-(const Point &obj) {
        Point ret;
        ret.x = x - obj.x;
        ret.y = y - obj.y;
        return ret;
    }
    int operator[](string s) {
        if (s == "x") return x;
        else return y;
    }
private :
    friend Point operator+(const Point &a, const Point &b);
    friend ostream &operator<<(ostream &out, const Point &obj);
    int x, y;
};

Point operator+(const Point &a, const Point &b) {
    Point ret;
    ret.x = a.x + b.x;
    ret.y =  a.y + b.y;
    return ret;
}

ostream &operator<<(ostream &out, const Point &a) {
    cout << "<Point> " << a.x << " , " << a.y << endl;
}

int main() {
    Point a(2, 4), b(5, 3);
    Point c = a + b;
    Point d = a + b + c;
    Point e = d - b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << a(5) << endl;
    cout << a["x"] << " " << a["y"] << endl;
    return 0;
}
