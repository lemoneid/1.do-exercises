/*************************************************************************
	> File Name: 32.lambda.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 17时05分06秒
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
#include <functional>
using namespace std;

auto add = [](int a, int b) mutable ->decltype(a + b){
    if (a == 1) return a + b; //第一个return语句auto确定类型
    else{
        //return [](){};
        return a * b;
    } 
};

auto Data = [](int a, int b) {
    return [=](auto func) {
        return func(a, b);
    };
};

auto First = [](int a, int b) {
    return a;
};

auto second = [](int a, int b) {
    return b;
};
auto Add = [](int a, int b) {
    return a + b;
};

function<int()> Temp_func() {
    int a = 23;
    return [=]()->int { //默认不可以访问外部变量
        return a;
    };
}

auto MAX = [](int a, int b) {
    return max(a, b);
};

int main() {

    cout << add(2, 4) << endl;
    auto func = Temp_func();
    cout << func() << endl;
    auto a =Data(rand() % 1000, rand() % 1000);
    cout << a(First) << endl;
    cout << a(second) << endl;
    cout << a(Add) << endl;
    cout << a(MAX);
    return 0;
}
