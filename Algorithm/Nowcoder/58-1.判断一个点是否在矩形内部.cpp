/*************************************************************************
	> File Name: 58-1.判断一个点是否在矩形内部.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月05日 星期一 17时25分13秒
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
typedef struct node {
    double x, y;
} node;
 
node point[5];
 
// p1->p2 * p1->p
 
double get_cross(node p1, node p2, node p) {
    return (p2.x - p1.x) * (p. y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
}
 
int main() {
    for (int i = 1; i < 5; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    cin >> point[0].x >> point[0].y;
    if (get_cross(point[1], point[2], point[0]) * get_cross(point[3], point[4], point[0]) >= 0) {
        cout << "No" << endl;
        return 0;
    }
     
    if (get_cross(point[1], point[3], point[0]) * get_cross(point[2], point[4], point[0]) >= 0) {
        cout << "No" << endl;
        return 0;
    }
 
    cout << "Yes" << endl;
    return 0;
}
