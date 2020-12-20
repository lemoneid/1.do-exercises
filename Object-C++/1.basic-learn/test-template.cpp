/*************************************************************************
	> File Name: test-template.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 10时00分15秒
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

template <typename T>
void print(const T &obj) {
    cout << obj << endl;
}

template <typename T, typename ...ARGS>
void print(const T &obj, ARGS ...args) {
    print(args...);
};

//ARG<4, int, double, int, int, int>;
template <int ind, typename T, typename ...ARGS>
class ARG {
public :
    typedef typename ARG<ind - 1, ARGS...>::getT getT;
};

template <typename T>
class ARG<0, T> {
public : 
    typedef T getT;
    typedef T finalT;
};

template <typename T, typename ...ARGS> 
class ARG<0, T, ARGS...>{
public :
    typedef T getT;
};


template <typename T, typename ...ARGS> class Test;
template <typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::getT b) {
        return a + b;
    }
};

int main(){
    print(123, "hello world", 78.9, '0');
    cout << sizeof(ARG<0, int,double, char>::getT) << endl;
    cout << sizeof(ARG<1, int,double, char>::getT) << endl;
    cout << sizeof(ARG<2, int,double, char>::getT) << endl;
    ARG<0, int, double, char>::getT a = 1.2;
    ARG<1, int, double, char>::getT b = 1.112;
    ARG<2, int, double, char>::getT c = 'a';
    cout << a << " " << b << " " << c << endl;
    //Test<int, double, float> d;
    Test<int(double, float)> d;
    //Test<int(double, float, char)> e;
    //Test<int(double)> f;
    //ARG<int, double, double, float, int>::rest::rest::rest::rest::getT g;
    //ARG<4, int, double, int, int, int>
    cout << d(2.3, 4.5) << endl;
    return 0;
}

