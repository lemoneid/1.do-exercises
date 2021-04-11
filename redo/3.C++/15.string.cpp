/*************************************************************************
	> File Name: 15.string.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月07日 星期三 20时50分39秒
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

class MyString {
public :
    MyString();
    MyString(const char *str);
    MyString(const MyString &obj);
    int size() const;
    MyString operator+=(const char *str);
    MyString operator+(const char *str);
    char &operator[](int idx) const;
    bool operator<(const MyString &obj);
    bool operator>(const MyString &obj);
    bool operator==(const MyString &obj);
    bool operator!=(const MyString &obj);
    friend ostream& operator<<(ostream &out, const MyString &obj);
    friend istream& operator>>(istream &input, MyString &obj);

private :
    int getLen(const char *str);
    bool expand(const char *data, int oldSize, int newSize) {
        char *tmp = new char[newSize]{0};
        for (int i = 0; i < oldSize; i++) {
            tmp[i] = data[i];
        }
        delete data;
        data = tmp;
        return true;
    }
    int _size;
    int _capacity;
    char *_data;
};

int main() {
    MyString a;
    a = "123124";
    cout << a.size() << endl;
    a += "abc";
    cout << a << endl;
    a = a + "123";

    cout << a << endl;
    cout << a[1] << endl;
    MyString b = a;
    MyString c;
    cin >> c;
    if (a < b) {
        cout << "a < b" << endl;
    } else if (a == b) {
        cout << "a == b" << endl;
    } else if (a > b) {
        cout << "a > b" << endl;
    }

    return 0;
}

int MyString::getLen(const char *str) {
    if (str == NULL) return 0;
    int ind = 0;
    while (str[ind]) ind++;
    return ind;
}

MyString::MyString() : _size(0), _capacity(0), _data(new char[1]{'\0'}) {}
MyString::MyString(const char * str) : _size(getLen(str)), _capacity(_size * 2 + 1), _data(new char[_size + 1]{'\0'}) {
    if (str == nullptr) return ;
    for (int i = 0; str[i]; i++) {
        _data[i] = str[i]; 
    }
    return ;
}
MyString::MyString(const MyString &obj) {
    if (&obj == nullptr || obj.size() == 0) {
        _size = 0;
        _capacity = 1;
        _data = new char[1]{'\0'};
        return ;
    }
    _size = obj.size();
    _capacity = _size * 2 + 1;
    _data = new char[_capacity]{'\0'};
    for (int i = 0; obj[i]; i++) {
        this->_data[i] = obj[i];
    }
}

int MyString::size() const {
    return this->_size;
}
MyString MyString::operator+=(const char *str) {
    if (str == nullptr) {
        return *this;
    }
    int newSize = _size + getLen(str);
    if (newSize >= _capacity) {
    }
    _size += getLen(str);
    _capacity = _size * 2 + 1;
    _data = new char[_capacity]{0};
    for (int i = 0; str[i]; i++) {
        this->_data[i] = str[i];
    }
    return *this;
}
MyString MyString::operator+(const char *str) {
    int newSize = this->_size + strlen(str);
    char *tmp = new char[newSize + 1]{0};
    strcat(tmp, this->_data);
    strcat(tmp, str);
    MyString cur = MyString(tmp);
    delete tmp;
    return cur;
}
char &MyString::operator[](int idx) const {
    return this->_data[idx]; 
};
bool MyString::operator<(const MyString &obj) {
    if (&obj == nullptr) return false;
    for (int i = 0; this->_data[i] && obj._data[i]; i++) {
        if (this->_data[i] - obj._data[i]) return this->_data[i] < obj._data[i];
    }
    return this->_size < obj._size;
}
bool MyString::operator>(const MyString &obj) {
    return !operator<(obj) && !operator==(obj);
}
bool MyString::operator==(const MyString &obj) {
    if (&obj == nullptr) return false;
    if (this == &obj) return true;
    if (strcmp(this->_data, obj._data) == 0) return true;
    return false;
}
bool MyString::operator!=(const MyString &obj) {
    return !operator==(obj);
}
ostream& operator<<(ostream &out, const MyString &obj) {
    if (&obj == nullptr) return out;
    out << obj._data;
    return out;
}
istream& operator>>(istream &input, MyString &obj) {
    if (&obj == nullptr) return input;
    input >> obj._data;
    return input;
}
