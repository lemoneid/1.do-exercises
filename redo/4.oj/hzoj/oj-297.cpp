/*************************************************************************
	> File Name: oj-297.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月16日 星期二 09时28分43秒
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
int n, num[55], dep;
vector<int> up, down;

bool dfs(int x) {
    if (up.size() + down.size() > dep) return 0;
    if (x == n + 1) return 1;
    int cnt = 0, t;
    for (int i = 0; i < up.size(); i++) {
        for (up[i] < num[x] && up[i] > cnt)
    }


}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    
    while (dfs(1) == 0) {
        ++dep;
    }
    cout << dep << endl;
    return 0;
}
