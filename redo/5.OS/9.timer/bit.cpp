/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月13日 星期二 17时09分41秒
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
#include <ctime>
using namespace std;
class my_sigset {
public :
    my_sigset() {
        memset(data, 0, sizeof(data));
    }
    void add(int val) {
        data[val >> 3] |= (1 << (val & MASK));
        printf("add val  : %d\n", val);
        printf("the idx %d at %d\n", val >> 3, val & MASK);
    }
    void clear(int val) {
        data[val >> 3] &= (~(1 << (val & MASK)));
        printf("del val  : %d\n", val);
    }
    bool is_member(int val) {
        return data[val >> 3] & (1 << (val & MASK));
    }
    void print() {
        for (int i = 0; i < SIGSET_SIZE; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d", (data[i] & (1 << j) ? 1 : 0));
            }
            printf("  ");
        }
        printf("\n");
    }
private : 
    //static const int SIGSET_SIZE =  (1024 / sizeof(unsigned long int));
    static const int SIGSET_SIZE = 5;
    static const int MASK = 0x7;
    unsigned long int data[SIGSET_SIZE];
};

int main() {
    srand(time(0));
    my_sigset arr;
    for (int i = 0; i < 20; i++) {
        if (rand() % 4 == 0) {
            arr.clear(rand() % 30);
        } else {
            arr.add(rand() % 30);
        }
        arr.print();
    }
    return 0;
}
