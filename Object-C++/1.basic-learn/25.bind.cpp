/*************************************************************************
	> File Name: 25.bind.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 17时54分05秒
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

void func(double x, int y, int z) {
    cout << x * 1.1 << " " << y << " " << z << endl;
}

struct A {
    void say() {
        cout << this << " : saying" << endl;
    }
    void run() {
        cout << "hello world" << endl;
    }
};

void count_function_times(function<void()> p,int &cnt) {
    p();
    cnt += 1;
    return ;
}

int main() {
    std::function<void(int, double)> f = bind(func, std::placeholders::_2, 123, std::placeholders::_1);
    f(1, 2.1);
    f(3, 4);
    A a;
    cout << &a << endl;
    std::function<void()> f2 = bind(&A::say, ref(a));
    f2();
    int cnt = 0;
    function<void()> f3 = bind(&A::run, ref(a));
    function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
    int i;
    for (i = 0;  i < rand() % 10; ++i) {
       f4(); 
    }
    cout << i << " : " << cnt << endl;
    return 0;
}
