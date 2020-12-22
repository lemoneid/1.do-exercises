/*************************************************************************
	> File Name: lambda.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月10日 星期四 19时55分22秒
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
#include <functional>
using namespace std;

int BindFunc(int a, int b, int c) {
    return max(max(a, b), c);
}

auto Data = [](int a, int b) {
    return [=](auto func){
        return func(a, b);
    };
};

auto First = [](int a, int b) { return a; };
auto Max = [](int a, int b) { return max(a, b); };


auto is_in = [](int a, int b) {
    return [=](int x) {
        return a <= x &&  x <= b;
    };
};

auto OR = [](auto f1, auto f2) {
    return [=](int x) {
        return f1(x) || f2(x);
    };
};

auto is_upper = is_in('A', 'Z');
auto is_lower = is_in('a', 'z');
auto is_digit = is_in(0, 9);
auto is_alpha = OR(is_upper, is_lower);
auto is_alnum = OR(is_digit, is_alpha);


int main() {
    auto bindFunc = bind(BindFunc, std::placeholders::_1, 10, 20);
    cout << bindFunc(1) << endl;
    cout << "------------test--------" << endl;
    auto func = Data(1, 2);
    cout << func(First) << endl;
    cout << func(Max) << endl;
    return 0;
}
