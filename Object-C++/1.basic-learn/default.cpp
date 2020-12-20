/*************************************************************************
	> File Name: default.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月14日 星期一 18时50分31秒
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
class A {
public :
    A() : z(0),w(this->x) {};
    A(const A &a) : z(8), w(this->x) {
        this->x = a.x;
        this->y = a.y;
    }
    A(int x, int y) : w(x), x(x), y(y), z(7) {}
private:
    int x, y;
    const int z;
    int &w;
};
int main() {
    A *p = new A;


    return 0;
}
