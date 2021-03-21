/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月21日 星期日 10时11分09秒
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
#define MAX_N 10
int num[MAX_N + 5], idx, n, m;
int mask[MAX_N + 5];

void p() {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void dfs(int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (mask[i]) continue;
        mask[i] = 1;
        num[idx++] = i;
        dfs(left - 1);
        idx--;
        mask[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(n); 
    return 0;
}
