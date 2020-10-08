/*************************************************************************
	> File Name: 59.判断一个点是否在三角形内部.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月05日 星期一 16时04分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef struct Point {
    double x, y;
    Point () {};
    Point (double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point operator+(const Point &b) {
        Point ret = (*this);
        ret.x += b.x;
        ret.y += b.y;
        return ret;
    }

    Point operator-(const Point &b) {
        Point ret = (*this);
        ret.x -= b.x;
        ret.y -= b.y;
        return ret;
    }
} Point;

Point node[4];

// p1->p2 * p1->p
double get_cross(Point p1, Point p2, Point p) {
    Point vec1 = p2 - p1;
    Point vec2 = p - p1;
    return vec1.x * vec2.y - vec1.y * vec2.x;
}

int main() {
    for (int i = 1; i < 4; ++i) {
        cin >> node[i].x >> node[i].y;
    }
    cin >> node[0].x >> node[0].y;
    if (get_cross(node[1], node[2], node[3]) < 0) {
        Point tmp;
        tmp.x = node[2].x;
        tmp.y = node[2].y;
        node[2].x = node[3].x;
        node[2].y = node[3].y;
        node[3].x = tmp.x;
        node[3].y = tmp.y;
    } 
    /*
    for (int i = 0; i < 4; ++i) {
        cout << i << " " << node[i].x << " " << node[i].y << endl;
    }
    */
    if (get_cross(node[1], node[2], node[0]) < 0) {
        cout << "No" << endl;
        return 0;
    }
    if (get_cross(node[2], node[3], node[0]) < 0) {
        cout << "No" << endl;
        return 0;
    }
    if (get_cross(node[3], node[1], node[0]) < 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}
