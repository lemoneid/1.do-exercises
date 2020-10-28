/*************************************************************************
	> File Name: oj-543.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Wed 02 Sep 2020 10:34:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n;
char mmap[25][25];
int check[25];
int ans = 0;

int dfs(int s) {
    for (int i = 1; i <= n; ++i) {
        if (mmap[s][i] == '1' && !check[i]) {
            check[i] = 1;
            if (s < n) dfs(s + 1);
            else if (s == n) ans++;
            check[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mmap[i][j];
        }
    }
    
    dfs(1);
    cout << ans << endl;

    return 0;
}
