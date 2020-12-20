/*************************************************************************
	> File Name: 11.int_array.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月15日 星期二 20时54分17秒
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

class IntArray {
public :
    IntArray(int n) : n(n) {
        this->arr = new int[n];
    }
    IntArray(const IntArray &obj) : n(obj.n) {
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = obj.arr[i];
        }
    }
    int &operator[](int ind) {
        if (ind >= 0) return this->arr[ind];
        else return this->arr[ind + n];
    }
    void operator+=(int x) {
        for (int i = 0; i < n; ++i) {
            arr[i] += x;
        }
    }
    IntArray &operator++() {
        for (int i = 0; i < n; ++i) {
            this->arr[i] += 1;
        } 
        return *this;
    }
    IntArray operator++(int x) {
        IntArray ret = (*this);
        for (int i = 0; i < n; ++i) {
            this->arr[i] += 1;
        }
        return ret;
    }
    ~IntArray() {
        delete[] arr;
    }
    friend ostream &operator<<(ostream &, const IntArray &);
private : 
    int *arr, n;
};

ostream &operator<<(ostream &out, const IntArray &a) {
    out << "<Class IntArray>" << endl;
    for (int i = 0; i < a.n; ++i) {
        out << a.arr[i] <<  " ";
    }
    return out;
}

int main() {
    srand(time(0));
    IntArray a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = rand() % 100;
    }
    cout << a[4] << endl;
    cout << a[-2] << endl;
    cout << a << endl;
    cout << (a++) << endl;
    cout << (++a) << endl;
    a += 5;
    cout << a << endl;
    return 0;
}
