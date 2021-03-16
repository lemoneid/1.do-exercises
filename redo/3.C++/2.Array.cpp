/*************************************************************************
	> File Name: 2.Array.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 13时25分57秒
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

template <typename T>
class Array {
public :
    Array(int x) : __size(x), __cnt(0) {
        data = new T[this->__size];
    }
    int size() {
        return this->__size;
    }
    void push_back(const T &a) {
        new(this->data + ((this->__cnt++))) T(a);
    }
    int operator[](int x) {
        return this->data[x];
    }
private :
    int __size, __cnt;
    T *data;
};

int main() {
    vector<int> arr(10);
    Array<int> arr2(10);
    cout << arr.size() << endl;
    arr.push_back(123);
    cout << arr[0] << endl;
    cout << arr.size() << endl;
    
    cout << arr2.size() << endl;
    arr2.push_back(123);
    cout << arr2[0] << endl;
    cout << arr2.size() << endl;
    int x = 0, y = 0;
    return 0;
}
