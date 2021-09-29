/*************************************************************************
	> File Name: 81.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 15时39分45秒
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

int solve(string &a, string &b) {
    vector<int> used(26, 0);
    for (int i = 0; i < a.size(); i++) {
        used[a[i] - 'a'] = 1;
    }
    for (int i = 0; i < b.size(); i++) {
        used[b[i] - 'a'] = 0;
    }
    for (int i = 0; i < 26; i++) {
        if (used[i]) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
    
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        if (a.size() > b.size()) swap(a, b);
        solve(a, b);
    }

    return 0;
}
