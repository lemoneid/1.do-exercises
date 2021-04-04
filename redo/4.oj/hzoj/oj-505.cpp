/*************************************************************************
	> File Name: oj-505.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 20时23分32秒
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

struct cmp {
    bool operator()(string &a, string &b) {
        return a + b > b + a;
    }
};

int main() {
    vector<string> arr;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }

    cout << endl;
    return 0;
}
