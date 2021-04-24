/*************************************************************************
	> File Name: 27.tuple.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月22日 星期四 15时15分23秒
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
using namespace std;

#define BEGIN(name) namespace name {
#define END }


BEGIN(worst)

void printf(const char *s) {
    while (*s) {
        if (*s == '%' && *++s != '%') {
            throw runtime_error("extra argument provided to printf");
        }
        cout << *s++;
    }
}

template<typename T, typename... Args>
void printf(const char *s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *++s != '%') {
            cout << value;
            return printf(++s, args...);
        }
        cout << *s++;
    }
    throw runtime_error("extra argument provided to printf");
}

END

int main() {
    worst::printf("hello\n");
    worst::printf("hello %s : %d %d\n", "test", 2);
    return 0;
}
