/*************************************************************************
	> File Name: hashTable.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 12时35分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <unordered_map>
#include "hashTable.h"
using namespace std;

struct A {
    A(int x, int y) : x(x), y(y) {}
    int x, y;
    bool operator==(A const &a) const {
        return this->x == a.x && this->y == a.y;
    }
};

struct myhash {
    int operator()(A const &a) const {
        return a.x + a.y;
    }
};


namespace worst {
    template<typename T, typename U>
    struct pair {
        pair() : first(), second() {}
        pair(const T &a) : first(a), second() {}
        pair(const T &a, const U &b) : first(a), second(b) {}
        T first;
        U second;
    };
    template<typename K> struct hash;
    template<>
    struct hash<int> {
        size_t operator()(int x) {
            return x;
        }
    };

    template<>
    struct hash<double> {
        size_t operator()(double x) {
            return *((size_t *)(&x));
        }
    };

    template<typename K, typename T, typename HashT = worst::hash<K>>
    class unordered_map {
    public :
        unordered_map(size_t size = 100) : size(size) {
            this->data = new pair<K, T> *[size];
            this->map = new bool[size];
            for (int i = 0; i < size; i++) {
                this->data[i] = nullptr;
                this->map[i] = false;
            }
        }
        T &operator[](const K &a) {
            size_t ind;
            T *value = this->find(a, ind);
            if (ind == -1) return *this->end();
            if (value == this->end()) {
                this->data[ind] = new pair<K, T>(a);
                this->map[ind] = true;
            }
            return this->data[ind]->second;
        }
        T *end() { return (T *)(0); }
        T *find(const K &a, size_t &ind) {
            ind = hash_func(a);
            ind %= this->size;
            size_t times = 1;
            while (this->map[ind] && !(this->data[ind]->first == a)) {
                ind += times * times;
                ind %= this->size;
                times += 1;
                if (times == this->size) {
                    ind = -1;
                    return this->end();
                }
            }
            if (this->map[ind]) return &(this->data[ind]->second);
            return this->end();
        }
    private :
        size_t size;
        pair<K, T> **data;
        bool *map;
        HashT hash_func;
    };
}



int main() {
    A a(0, 9), b(10, 12);
    unordered_map<A, int, myhash> arr;
    arr[a] = 1;
    arr[b] = 2;
    cout << arr[a] << endl;
    cout << arr[b] << endl;
   // worst::unordered_map<int, int> arr2;
    worst::unordered_map<int, int> arr2;
    arr2[129883] = 65;
    arr2[623] = 23;
    cout << arr2[129883] << endl;
    cout << arr2[623] << endl;

    worst::unordered_map<A, int, myhash> arr3;
    arr3[a] = 1;
    arr3[b] = 2;
    cout << arr3[a] << endl;
    cout << arr3[b] << endl;
    return 0;
}
