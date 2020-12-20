/*************************************************************************
	> File Name: haizei-main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 11时52分49秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include "haizei-BSTree.h"
using namespace std;
class A {
public :
    void operator++() {
        cout << "no param" << endl;
    }
    void operator++(int) {
        cout << "has int param" << endl;
    }
};

int main() {
    haizei::BSTree<int> root_bs;
    std::set<int> root_s;
    for (int i = 0; i < 10; i++) {
        int x = rand() % 100;
        cout << x << endl;
        root_bs.insert(x);
        root_s.insert(x);
    }
    cout << endl;
    for (std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    for (haizei::BSTree<int>::iterator iter = root_bs.begin(); iter != root_bs.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
