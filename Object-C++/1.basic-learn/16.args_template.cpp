/*************************************************************************
	> File Name: 15.args_template.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月16日 星期三 20时29分23秒
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
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<typename T, typename ...ARGS>
struct ARG {
    typedef T getT;  
    typedef ARG<ARGS...> rest;
};

template<typename T>
struct ARG<T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test; //偏特化版本
template<typename T, typename ...ARGS> 
class Test<T(ARGS...)> {
//template<typename T, typename ...ARGS>
//class Test {
//    Test<int, double, float> d;
public :
    T operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::finalT b) {
        return a + b;
    }
};

int main(){
    print(123, "hello world", 78.9, '0');
    cout << sizeof(ARG<int,double, char>::getT) << endl;
    cout << sizeof(ARG<int,double, char>::rest::getT) << endl;
    cout << sizeof(ARG<int,double, char>::rest::rest::getT) << endl;
    ARG<int, double, char>::getT a = 1;
    ARG<int, double, char>::rest::getT b = 1.112;
    ARG<int, double, char>::rest::rest::getT c = 'a';
    cout << a << " " << b << " " << c << endl;
//    Test<int, double, float> d;
    Test<int(double, float)> d;
    //Test<int(double, float, char)> e;
    //Test<int(double)> f;
    //ARG<int, double, double, float, int>::rest::rest::rest::rest::getT g;
    //ARG<4, int, double, int, int, int>
    cout << d(2.3, 4.5) << endl;
    return 0;
}
