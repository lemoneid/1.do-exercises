/*************************************************************************
	> File Name: 21.template.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月19日 星期一 20时15分25秒
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


class A {
public :
    A() = delete;
    A(int x) : x(x), p(nullptr) {
        p = new int;
    }
    ~A() {
        if (p) delete p;
        cout << "A destructor" << endl;
    }
    friend ostream& operator<<(ostream &, const A &);
private :
    int x, *p;
};
ostream& operator<<(ostream &out, const A &obj) {
    out << "Class A : " << obj.x;
    //out << obj.x;
    return out;
}

BEGIN(worst) 
template <typename T>
class vector {
public:
    //vector(int n = 10) : __size(n), data(new T[__size]) {
    vector(int n = 10);
    vector(const vector<T> &v);
    vector(vector<T>&& v);
    T &operator[](int ind);
    const T &operator[](int ind) const;
    int size() const;
    void push_back(const T&);
    void push_back(T&&);
    ~vector();
private:
    int __capacity;
    int __size;
    T *data;
};
template<typename T>
vector<T>::vector(int n) : __capacity(n), __size(0), data(nullptr) {
     data = (T *)malloc(sizeof(T) * __capacity);
 }

template<typename T>
vector<T>::vector(const vector<T> &v) {
     __size = v.__size;
     __capacity= v.__capacity;
     data = (T *)malloc(sizeof(T) * __size);
     for (int i = 0; i < __size; i++) {
         //data[i] = v.data[i];
         //原地构造
         new (data + i)T(v.data[i]);
     }
 }

template<typename T>
vector<T>::vector(vector<T>&& v) : __size(v.__size), __capacity(v.capacity), data(v.data) {
     v.data = nullptr;
     v.__size = 0;
     v.__capacity = 0;
 }

template<typename T>
T &vector<T>::operator[](int ind){
     return data[ind];
 }


template<typename T>
const T &vector<T>::operator[](int ind) const {
    return data[ind];
}

template<typename T>
int vector<T>::size() const {
     return this->__size;
 }
template<typename T>
void vector<T>::push_back(const T&obj) {
    new (data + __size)T(obj);
    __size++;
    return ;
}
template<typename T>
void vector<T>::push_back(T&& obj) {
    new (data + __size)T(move(obj));
    __size++;
    return ;
}
template<typename T>
 vector<T>::~vector() {
     if (data) {
        for (int i = 0; i < __size; i++) {
            data[i].~T();
        }
        free(data);
     }
     __size = 0;
     __capacity = 0;
 }
END


int main() {
    vector<A> v;
    cout << v.size() << endl;
    v.push_back(123);
    v.push_back(456);
    cout << "debug" << endl;
    v.push_back(789);
    cout << v[0] << endl; 
    worst::vector<A> v2;
    cout << v2[0] << endl;
    cout << v2.size() << endl;
    cout << "test" << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << "end" << endl;
    return 0;
}
