/*************************************************************************
	> File Name: test.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月27日 星期二 18时33分33秒
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

typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> v(n + 1, vector<PII>(0));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(PII(b, c)); 
        v[b].push_back(PII(a, c));
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << " : ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << "(" << v[i][j].first << "," << v[i][j].second << ") ";
        }
        cout << endl;
    }
    return 0;
}
