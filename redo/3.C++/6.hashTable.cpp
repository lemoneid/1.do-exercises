/*************************************************************************
	> File Name: 4.hash.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 17时02分51秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <functional>
using namespace std;

class Node {
public :
    Node() : flag(false), str(nullptr) {}
    void clear() {
        this->flag = false;
        if (this->str) free(this->str);
        this->str = nullptr;
        return ;
    }
    void insert(const char *str) {
        this->clear();
        this->flag = true;
        this->str = strdup(str);
        return ;
    }
    bool empty() { return this->flag == false; }
    bool operator!=(const char *str) {
        if (this->str == nullptr) return true;
        return strcmp(this->str, str) != 0;
    }
    bool operator==(const char *str) {
        return !((*this) != str);
    }
    ~Node() {
        if (this->str) free(this->str);
        this->str = nullptr;
    }
private :
    bool flag;
    char *str;
};

class HashFunc {
public :
    virtual int operator()(const char *str) const = 0;
};

class HashTable {
public :
    typedef function<int(const char *)> HashFunc_T;
    HashTable(HashFunc_T func);
    bool insert(const char *str);
    bool find(const char *str);
    ~HashTable();
private:
    Node &find_position(const char *str);
    int _size;
    Node *data;
    HashFunc_T p_func;
};

class BKDRHash : public HashFunc {
public :
    int operator()(const char *str) const {
        int seed = 31;
        int hash_value = 0;
        for (int i = 0; str[i]; i++) {
            hash_value = hash_value * seed + str[i];
        }
        return hash_value & 0x7fffffff;
    }
};

int APHash(const char *str) {
    int hash = 0;
    for (int i = 0; str[i]; i++) {
        if (i % 2) {
            hash = (hash << 3) ^ str[i] ^ (hash >> 5);
        } else {
            hash = ~((hash << 7) ^ str[i] ^ (hash >> 11));
        }
    }
    return hash & 0x7fffffff;
}

int main() {
    BKDRHash bkdr_func;
    HashTable h1(bkdr_func), h2(APHash);
    int op;
    char str[100];
    while (cin >> op >> str) {
        switch (op) {
            case 0: {
                cout << "insert " << str << " to hash table 1= ";
                cout << h1.insert(str) << endl;
                cout << "insert " << str << " to hash table 2= ";
                cout << h2.insert(str) << endl;
            } break;
            case 1: {
                cout << "search " << str << " from hash table 1= ";
                cout << h1.find(str) << endl;
                cout << "search " << str << " from hash table 2= ";
                cout << h2.find(str) << endl;
            } break;
        }
    }
    return 0;
}

HashTable::HashTable(HashFunc_T func) : p_func(func) {
    this->_size = 100;
    this->data = new Node[this->_size];
}

bool HashTable::insert(const char *str) {
    Node &d = find_position(str);
    if (!d.empty()) return false;
    d.insert(str);
    return true;
}

bool HashTable::find(const char *str) {
    Node &d = find_position(str);
    return !d.empty();
}

Node &HashTable::find_position(const char *str) {
    int ind = p_func(str) % this->_size;
    int times = 1;
    while (!data[ind].empty() && data[ind] != str) {
        ind += times * times;
        ind %= this->_size;
    }
    return data[ind];
}

HashTable::~HashTable() {
    delete[] this->data;
}

