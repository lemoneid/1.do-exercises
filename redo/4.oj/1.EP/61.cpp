/*************************************************************************
	> File Name: 61.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 09时38分24秒
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

int Triangle(int n) {
    return (n * (n + 1)) / 2;
}

int Square(int n) {
    return n * n;
}

int Pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

int Hexagonal(int n) {
    return n * (2 * n - 1);
}

int Heptagonal(int n) {
    return n * (5 * n - 3) / 2;
}

int Octagonal(int n) {
    return n * (3 * n - 2);
}

int binary_search(int (*func)(int), int y) {
    int head = 1, tail = y, mid;
    while (head <= tail) {
        mid = (head + t)
    }
}


int main() {
    

    return 0;
}
