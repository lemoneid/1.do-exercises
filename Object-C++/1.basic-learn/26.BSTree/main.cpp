/*************************************************************************
	> File Name: main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 19时16分56秒
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
#include "BSTree.h"
#include <set>
using namespace std;

int main() {
    worst::BSTree<int> root;
    std::set<int> root_s;
    queue<int> q;
    for (int i = 0; i < 10; ++i) {
        int x = rand() % 100;
        root.insert(x);
        root_s.insert(x);
    }
    for (std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    for (worst::BSTree<int>::iterator iter = root.begin(); iter != root.end(); iter++) {
            cout << *iter << " ";        
    }
    cout << endl;
    return 0;
}
