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

int func(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {

    auto bindFunc = bind(func, std::placeholders::_1, 10, 20);
    cout << bindFunc(1) << endl;
    return 0;
}
