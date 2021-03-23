/*************************************************************************
	> File Name: 14.template.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 20时34分20秒
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

template<typename T>
T add(T a, T b) {
    cout  << "add function : " << sizeof(T) << endl;
    static int i = 0;
    cout << "i : " << ++i << endl;
    return a + b; 
}

template<typename T>
class Array {
public :
    Array(int n) : n(n) {
        this->arr = new T[n];
    }

    T &operator[](int ind) {
        if (ind < 0 || ind >= n) return end;
        return this->arr[ind];
    }

private :
    int n;
    T __end;
};

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;

    cout << add<int>(3, 12.33) << endl;

    return 0;
}
