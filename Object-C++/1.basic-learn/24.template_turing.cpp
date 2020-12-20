/*************************************************************************
	> File Name: 24.template_turing.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 16时31分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

template<int x>
struct IsOdd {
    constexpr static int r = x % 2; //constexp编译器常量
};


template<int i, int x>
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));  
};

template<int i, int x, int k>
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r>::r;
};

template<int i, int x> 
struct Test<i , x, 0> {
    constexpr static int r = 1;
};

template<int i, int x> 
struct Test<i , x, 1> {
    constexpr static int r = 1;
};

template<int i, int x> 
struct Test<i , x, 2> {
    constexpr static int r = 1;
};

template<int x>
struct isPrime {
    constexpr static int r = Test<2, x, 2>::r; //constexp编译器常量
};

bool __is_prime(int i, int x) {
    if (i * i > x) return true; // k == 0;
    if (x % i == 0) return false; // k == 1;
    return __is_prime(i + 1, x); // k == 2;
}

bool is_prime(int x) {
    for (int i = 2; i  * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cout << IsOdd<5>::r << endl;
    cout << IsOdd<6>::r << endl;
    cout << isPrime<9973> << endl;
    cout << isPrime<10000> << endl;
    return 0;
}
