/*************************************************************************
	> File Name: 39.数组中未出现的最小正整数.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 12时33分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 1000000

int num[MAX_N + 5];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int l = 0;
    int r = n;
    while (l < r) {
        if (num[l] == l + 1) {
            l++;
        } else if (num[l] <= l || num[l] > r || num[l] == num[num[l] - 1]) {
            num[l] = num[--r];
        } else {
            swap(num[l], num[num[l] - 1]);
        }
    }
    cout << l + 1 << endl;
    return 0;
}
