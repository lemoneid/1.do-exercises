/*************************************************************************
	> File Name: 24.奇数下标都是奇数.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月27日 星期日 21时58分41秒
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
#define MAX_N 100000
int num[MAX_N + 5];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int even = 0;
    int odd = 1;
    int end = n - 1;
    while (even < n && odd < n) {
        if (num[end] & 1) {
            swap(num[odd], num[end]);
            odd += 2;
        } else {
            swap(num[even], num[end]);
            even += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << num[i];
    }
    return 0;
}
