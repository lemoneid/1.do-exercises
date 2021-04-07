/*************************************************************************
	> File Name: oj-542-奶酪.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 16时06分16秒
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
const int MAX_N = 1000;
struct Node {
    int x, y, z;
} arr[MAX_N + 5];

int n, h, r;
int s[MAX_N + 5], e[MAX_N + 5];
bool mask[MAX_N + 5];
bool check(Node &a, Node &b) {
    double x = fabs(a.x - b.x);
    double y = fabs(a.y - b.y);
    double z = fabs(a.z - b.z);
    return sqrt(x * x + y * y + z * z) <= 2 * r;
}

int dfs(int now) {
    if (e[now] == 1) return true;
    for (int i = 0; i < n; i++) {
        if (mask[i] || check(arr[now], arr[i]) == false) continue;
        mask[i] = true;
        if (dfs(i)) return true;
    } 
    return false;
}

void solve() {
    memset(mask, false, sizeof(mask));
    memset(s, 0, sizeof(s));
    memset(e, 0, sizeof(e));
    cin >> n >> h >> r;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        if (arr[i].z <= r) {
           s[++s[0]] = i; 
        }
        if (arr[i].z + r >= h) {
            e[i] = 1;
        }
    }
    for (int i = 1; i <= s[0]; i++) {
        if (mask[s[i]]) continue;
        if (dfs(s[i])) {
            cout << "Yes" << endl;
            return ;
        }
    }
    cout << "No" << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
