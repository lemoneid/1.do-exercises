/*************************************************************************
	> File Name: 4.IntArray.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 17时23分01秒
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

class IntArray {
public :
    IntArray(int x) : _size(x) {
        num = new int[this->_size];
    }
    IntArray(const IntArray &obj) : _size(obj._size) {
        this->num = new int[_size];
        for (int i = 0; i < _size; i++) {
            num[i] = obj.num[i];
        }
    }
    int &operator[](int ind) {
        if (abs(ind) >= _size) return num[0];
        if (ind >= 0) return num[ind];
        return num[ind + _size];
    }
    void operator+=(int x) {
        for (int i = 0; i < _size; i++) {
            num[i] += x;
        }
    }
    IntArray &operator++() {
        for (int i = 0; i < _size; i++) {
            num[i] += 1;
        }
        return (*this);
    }
    IntArray operator++(int x) {
        IntArray res(*this);
        for (int i = 0; i < _size; i++) {
            num[i] += 1;
        }
        return res;
    }

    ~IntArray() {
        if (num != nullptr) delete[] num;
        num = nullptr;
    }
    friend ostream &operator<<(ostream &out, const IntArray &);
private : 
    int *num, _size;
};

ostream &operator<<(ostream &out, const IntArray &obj) {
    for (int i = 0; i < obj._size; i++) {
        out << obj.num[i] << " ";
    }
    return out;
}
int main() {
    srand(time(0));
    IntArray a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    cout << a[4] << endl;
    cout << a[-2] << endl; // 输出倒数第 2 位的值
    cout << a << endl; // 输出整个数组中的元素
    a += 5; // 给数组中所有元素都加5
    cout << a << endl; // 输出整个数组中的元素
    cout << (a++) << endl; // 给数组中的所有元素都加 1
    cout << (++a) << endl; // 给数组中的所有元素都加 1
    return 0;
}
