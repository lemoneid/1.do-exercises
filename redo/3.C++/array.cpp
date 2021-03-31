/*************************************************************************
	> File Name: array.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月29日 星期一 13时08分47秒
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

class Array {
public :
    Array(int n) : n(10) {
        data = new int[10];
    }
    Array(const Array &a) {
        this->n = a.n;
    }
    int &operator[](int ind) {
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
    size_t size() {return this->n; }
    friend ostream&  operator<<(ostream &out, const Array &obj);
    ~Array() {
        delete[] data;
        data = nullptr;
    }
private :
    int *data, end;
    size_t n;
};

ostream&  operator<<(ostream &out, const Array &obj) {
    for (int i = 0; i < obj.n; i++) {
        i && out << " ";
        out << obj.data[i];
    }
    return out;
}

int main() {
    Array arr(10);
    arr[2] = 2;
    cout << arr[2] + 3 << endl;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100;
    }
    cout << endl;
    cout << arr << endl;

    return 0;
}
