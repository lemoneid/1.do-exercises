/*************************************************************************
	> File Name: oj-233.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 10时55分33秒
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
#define MAX_N 10000
int arr[MAX_N + 5];

int main() {
    int n, m, p, h;
    cin >> n >> p >> h >> m;
    for (int i = 1; i <= n; i++) {
        arr[i] = h;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int x = min(arr[a], arr[b]), flag = 1;
        for (int j = a + 1; j < b; j++) {
            if (arr[j] < x) continue;
            flag = 0;
        }
        if (!flag) {
            for (int j = a + 1; j < b; j++) {
                arr[j] -= 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
