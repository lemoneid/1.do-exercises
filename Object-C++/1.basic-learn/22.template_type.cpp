/*************************************************************************
	> File Name: template_type.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 16时07分07秒
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

template<typename T>

void my_swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a;
    a = b;
    b = c;
    return ;
}

template <typename T>
void add(T &&a, T &&b) { //&和&&都表示传引用
    a += 3;
    b += 4;
}


void func(void (*p)(int &, int &), int &a, int &b) {
    p(a, b);
    return ;
}

int main() {
    int a = 123, b = 456;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(move(a), move(b));
    cout << a << " " << b << endl;
    func(add, a, b);
    cout << a << " " << b << endl;
    return 0;
}
