/*************************************************************************
	> File Name: 30.constexpr.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 16时28分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

constexpr int f(int i) { //可以返回一个编译期常量对象,而不是必须,也可以返回运行期对象
    return 2 * i;
}

struct A {
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};

int main() {
    int n = 3;
    cin >> n;
    const int a = n + 123; //运行期常量,不可修改的量,只读的变量
    cout << a << endl;
    constexpr int b = 3; //编译期常量
    constexpr int c = f(123) + 567; 
    constexpr A d(2, 3);
    return 0;
}
