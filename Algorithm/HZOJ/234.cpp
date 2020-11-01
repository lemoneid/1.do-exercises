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

struct Data {
    int size;
    int data[5];
} heap[20];

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

void output() {
    for (int i = 1; i < 14; ++i) {
        for (int j = 1; j < 5; ++j) {
            cout << heap[i].data[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    for (int i = 1; i < 14; ++i) {
        char ch;
        for (int j = 1; j <= 4; ++j) {
            cin >> ch;
            heap[i].data[j] = mmap[ch];
        }
        heap[i].size = 4;
    }


    int left = 4;
    int now = heap[13].data[1];
    heap[13].size--;

    while (left) {
        check[now]++;
        if (now == 13) {
            left--;
            if (left == 0) break;
            now = heap[13].data[5 - heap[now].size--];
        } else {
            now = heap[now].data[heap[now].size--];
        }
    } 
    int ans = 0;
    for (int i = 1; i < 13; ++i) {
        if (check[i] == 4) ans++;
    }

    cout << ans << endl;
    return 0;
}
