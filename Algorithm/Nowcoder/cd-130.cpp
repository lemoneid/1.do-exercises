/*************************************************************************
	> File Name: cd-130.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 17时56分43秒
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
using namespace std;

vector<string> arr;
string input;
int n;

bool cmp(string a, string b) {
    if (a[0] - b[0]) return a[0] < b[0];
    return a + b < b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (auto cur : arr) {
        cout << cur;
    }
    cout << endl;
    return 0;
}
