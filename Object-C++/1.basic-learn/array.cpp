/*************************************************************************
	> File Name: array.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月25日 星期三 13时51分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;
class MyArray
{
private:
    int *m_p;//数组空间的起始地址
    size_t m_len;//申请的数组元素个数
public:
    MyArray(size_t n);//n 表示申请的动态数组元素个数。 
    ~MyArray();
    MyArray(const MyArray &a);
    MyArray &operator=(const MyArray &a);
    int &operator[](size_t index);
    const int &operator[](size_t index) const;
    friend ostream& operator<<(ostream &out, const MyArray &a);
};

MyArray::MyArray(size_t n) {
    m_len = n >= 0 ? n : 0;
    if (n == 0) m_p = nullptr;
    else m_p = new int[n];
}
MyArray::~MyArray() {
    m_len = 0;
    if (m_p != nullptr) delete m_p;
}
MyArray::MyArray(const MyArray &a) {
    if (a.m_len == 0) return ;
    m_len = a.m_len;
    m_p = new int[m_len];
    memcpy(m_p, a.m_p, sizeof(int) * m_len);
}
MyArray& MyArray::operator=(const MyArray &a) {
    if (a.m_len == 0) return *this;
    m_len = a.m_len;
    m_p = new int[m_len];
    memcpy(m_p, a.m_p, sizeof(int) * m_len);
}

int &MyArray::operator[](size_t index) {
	if (index < 0 || index >= m_len) {
        cout << "the index is error!" << endl;
	}
	return m_p[index];
}

const int& MyArray::operator[](size_t index) const {
	if (index < 0 || index >= m_len) {
        cout << "const the index is error!" << endl;
	}
	return m_p[index];
}

ostream& operator<<(ostream &out, const MyArray &a) {
    cout << "the array[" << a.m_len << "] = ";
    for (int i = 0; i < a.m_len; ++i) {
        i && out << " ";
        out << a.m_p[i];
    }
    return out;
}

int main() {
    srand(time(0));
    MyArray a1(10);    
    for (int i = 0; i < 5; ++i) {
        a1[i] = rand() % 100;
    }
    MyArray a2(a1);
    MyArray a3 = a1;
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    a1[11];
    a2[10];
    a3[11];
    cout << a2[9] << endl;
    return 0;
}
