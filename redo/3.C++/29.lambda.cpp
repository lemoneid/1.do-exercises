/*************************************************************************
	> File Name: 27.lambda.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月26日 星期一 09时41分02秒
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
#include <memory>
using namespace std;

int main() {
    auto f1 = []() {
        auto x = std::make_shared<int>(0);
        static int val = 0;
        auto a = [=]()  {
            return ++(*x); 
        };
        cout << "x : " << *x << endl;
        auto b = [=]()  {
            return ++(*x); 
        };
        cout << "x : " << *x << endl;
        return make_pair(a(), b());
    };
    auto obj = f1();
    cout << typeid(obj).name() << endl;
    cout << obj.first << " " << obj.second << endl;


    return 0;
}
