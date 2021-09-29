/*************************************************************************
	> File Name: hj76.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 14时15分56秒
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
    while (cin >> n) {
        long long val = n * (n - 1) + 1;
        for (int i = 0; i < n; i++) {
            i && cout << "+";
            cout << val;
            val += 2;
        }
        cout << endl;
    }

    return 0;
}
