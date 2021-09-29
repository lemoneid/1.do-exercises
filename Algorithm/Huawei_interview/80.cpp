/*************************************************************************
	> File Name: 80.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 15时24分11秒
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

int solve(int n) {
    int m;
    set<int> a;
    for (int i = 0, val; i < n; i++) {
        cin >> val;
        a.insert(val);
    }
    cin >> m;
    for (int i = 0, val; i < m; i++) {
        cin >> val;
        a.insert(val);
    }
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
    return 0;
}

int main() {
    int n;
    while (cin >> n)  solve(n);
    return 0;
}
