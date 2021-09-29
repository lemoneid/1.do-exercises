/*************************************************************************
	> File Name: hj68.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 11时37分36秒
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
vector<pair<string, int>> arr;
static bool cmp_0(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}
static bool cmp_1(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second <= b.second;
}
int main() {
    int n, flag;
    while (cin >> n >> flag) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        if (flag == 0) sort(arr.begin(), arr.end(), cmp_0);
        else if (flag == 1) sort(arr.begin(), arr.end(), cmp_1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i].first << " " << arr[i].second << endl;
        }
    }
    return 0;
}
