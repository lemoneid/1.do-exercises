/*************************************************************************
	> File Name: HJ14.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月18日 星期六 14时34分45秒
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

int main() {
    int n;
    vector<string> vec;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        cout << "i : "  << i << " | " << str << endl;
        vec.push_back(str);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}

