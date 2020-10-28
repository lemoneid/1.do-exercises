/*************************************************************************
	> File Name: 234.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月28日 星期三 18时00分44秒
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
#include <unordered_map>
using namespace std;

int heap[20][5];
int check[20];
unordered_map<char,int> mmap;

void init() {
    for (char i = '2'; i <= '9'; ++i) {
        mmap[i] = i - '0';
    }
    mmap['A'] = 1;
    mmap['0'] = 10;
    mmap['J'] = 11;
    mmap['Q'] = 12;
    mmap['K'] = 13;
    return ;
}

int main() {
    for (int i = 1; i < 14; ++i) {
        char ch;
        for (int j = 1; j <= 4; ++j) {
            cin >> ch;
            heap[i][j] = mmap[ch];
        }
    }
    int left = 4;
    int now = heap[13][1];
    


    return 0;
}
