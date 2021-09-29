/*************************************************************************
	> File Name: hj77.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 14时21分49秒
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
int a[20][2], s[20], top;

bool is_valid(int n) {
    int j = 0;
    top = -1;
    for (int i = 0; i < n; i++) {
        while (j < a[i][0]) {
            s[++top] = (++j);
        }
        if (top == -1 || s[top] - a[i][0]) return false;
        --top;
    }
    return true;
}
vector<string> result;
int solve(int n) {
    for (int i = 0; i < n; i++) cin >> a[i][1], a[i][0] = i + 1;
    do {
        if (!is_valid(n)) continue;
        string s;
        for (int i = 0; i < n; i++) {
            if (i) s =  s + ' ';
            int val = a[i][1];
            s += to_string(val);
        }
        result.push_back(s);
    } while (next_permutation(a, a + n));
    sort(result.begin(), result.end());
    for (auto cur : result) cout << cur << endl;
    return 0;
}

int main() {
    int n;
    while (cin >> n) solve(n);
    return 0;
}
