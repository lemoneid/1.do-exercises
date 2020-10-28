/*************************************************************************
	> File Name: 58.判断一个点是否在矩形内部.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月05日 星期一 13时54分33秒
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
#include <cmath>
using namespace std;

typedef struct node {
    double x, y;
} node;

node point[5];

bool is_inside(node leftup, node rightdown, node tar) {
    if (tar.x <= leftup.x || tar.x >= rightdown.x) {
        return false;
    }
    if (tar.y >= leftup.y || tar.y <= rightdown.y) {
        return false;
    }
    return true;
}

bool calc() {
    if (point[1].y == point[2].y) {
        return is_inside(point[1], point[4], point[5]);
    }
    double xx = fabs(point[3].x - point[4].x);
    double yy = fabs(point[3].y - point[4].y);
    double l = sqrt(xx * xx + yy * yy);
    double sin = yy / l;
    double cos = xx / l;
    node leftup, rightdown, tar; 
    leftup.x = point[1].x * cos + point[1].y * sin;
    leftup.y = point[1].y * cos - point[1].x * sin;
    rightdown.x = point[4].x * cos + point[4].y * sin;
    rightdown.y = point[4].y * cos - point[4].x * sin;
    tar.x = point[5].x * cos + point[5].y * sin;
    tar.y = point[5].y * cos - point[5].x * sin;
    
    /*
    cout << "sin = " << sin << " cos = " << cos << endl;
    cout << leftup.x << " " << leftup.y << endl;
    cout << rightdown.x << " " << rightdown.y << endl;
    */
    return is_inside(leftup, rightdown, tar);
}


int main() {
    for (int i = 1; i <= 5; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    cout << (calc() ? "Yes" : "No") << endl;
    return 0;
}
