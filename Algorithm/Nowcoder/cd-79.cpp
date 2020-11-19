/*************************************************************************
	> File Name: cd-79.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 12时40分20秒
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
#define MAX_N 100000

int arr[MAX_N], check[MAX_N + 5];
int n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int need = 1;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        check[x] = 1;
        if (x == need) {
            int tmp = need;
            while (check[tmp] && tmp <= n) {
                cout << tmp++ << " " << need << endl; 
            } 
            need = tmp;
        }
    }

    return 0;
}
