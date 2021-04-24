/*************************************************************************
	> File Name: 19.value.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月19日 星期一 12时59分21秒
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
class vector {
public:
    vector(int n = 10) : __size(n), data(new int[n]) {
        cout << "default constructor" << endl;
    }
    vector(const vector &v) : __size(v.__size), data(new int[__size]) {
        cout << "deep copy constructor" << endl;
        for (int i = 0; i < this->size(); i++) {
            data[i] = v.data[i];
        }
    }
    vector(vector&& v) : __size(v.size()), data(v.data) {
        cout << "move copy constructor" << endl;
        v.data = nullptr;
        __size = 0;
    }
    vector operator+(const vector &v) {
        vector ret(v.size() + this->size());
        cout << "operator + " << endl;
        vector &now = *this;
        for (int i = 0; i < size(); i++) {
            ret[i] = now[i];
        }
        for (int i = size(); i < ret.size(); i++) {
            ret[i] = v[i - size()];
        }
        return ret;
    }
    int &operator[](int ind) const {
        return this->data[ind];
    }
    int size() const {
        return this->__size;
    }
    ~vector() {
        if (this->data) delete[] this->data;
    }
private :
    int __size;
    int *data;
};
END
ostream &operator<<(ostream &out, const worst::vector &obj) {
    for (int i = 0; i < obj.size(); i++) {
        i && out << " ";
        out << obj[i];
    }
    return out;
}
int main() {
    worst::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    worst::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    return 0;
}
