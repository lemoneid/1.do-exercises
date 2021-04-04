/*************************************************************************
	> File Name: oj-637.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月04日 星期日 10时15分22秒
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
#include <queue>
using namespace std;
const int MAX_N = 26;
const char BEGIN_LETTER = 'A';

int n, m;
int ans[MAX_N + 5][MAX_N + 5], matrix[MAX_N + 5][MAX_N + 5];
int l[MAX_N + 5], r[MAX_N + 5], in_degree[MAX_N + 5];
char seq[MAX_N + 5];

int haveCycle(int n) {
    memset(in_degree, 0, sizeof(in_degree));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) in_degree[j]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < n; i++) {
            if (matrix[now][i] == 0) continue;
            in_degree[i]--;
            if (in_degree[i] == 0) que.push(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (in_degree[i]) return 1;
    }
    return 0;
}

int floyed(int n) {
    memset(ans, 0x3f, sizeof(ans));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) ans[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == 0x3f3f3f3f) continue;
            r[i]++;
            l[j]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] + l[i] == n - 1) cnt++;
        seq[l[i]] = i + BEGIN_LETTER;
    }
    seq[n] = '\0';
    return cnt == n;
}

int main() {
    cin >> n >> m;
    char str[10];
    int flag = 0, ind = -1;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (flag) continue;
        matrix[str[0] - BEGIN_LETTER][str[2] - BEGIN_LETTER] = 1;
        if (haveCycle(n)) {
            flag = 1;
            ind = i + 1;
        }
        if (floyed(n)) {
            flag = 2;
            ind = i + 1;
        }
    }
    if (flag == 0) {
        cout << "Sorted sequence cannot be determined." << endl;
    } else if (flag == 1) {
        cout << "Inconsistency found after "<< ind << " relations." << endl;
    } else {
           cout << "Sorted sequence determined after " << ind << " relations: " << seq << "." << endl;
    }
    return 0;
}
