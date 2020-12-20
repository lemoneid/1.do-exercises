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

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T getT;
    typedef typename ARG<0, ARGS...>::finalT finalT;
};

template<typename T>
struct ARG<0, T> {
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
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};

int main(){
    print(123, "hello world", 78.9, '0');
//    Test<int, double, float> d;
    Test<int(double, float)> d;
    //Test<int(double, float, char)> e;
    //Test<int(double)> f;
    //ARG<int, double, double, float, int>::rest::rest::rest::rest::getT g;
    ARG<4, int, double, int, int, int> g;
    cout << d(2.3, 4.5) << endl;

    return 0;
}
