/*************************************************************************
	> File Name: oj-376.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 20时02分13秒
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
#include <queue>
#include <map>
using namespace std;
#define MAX_N 1000
int mask[MAX_N + 5];
int ans = 0;
queue<int> que;
int main() {
    int m, n;
    cin >> m >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mask[x]) continue;
        ans++;
        que.push(x);
        if (que.size() > m)  {
            mask[que.front()] = 0;
            que.pop();
        }
        mask[x] = 1;
    }
    cout << ans << endl;
    return 0;
}
