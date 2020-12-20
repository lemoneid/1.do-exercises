/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月24日 星期二 18时30分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
#define MAX_V 100000
#define MAX_W 1000000

int dp[MAX_V + 5];
typedef pair<int, int> PII;
deque<PII> que;
int main() {
    int mostv, n;
    cin >> mostv >> n;
    for (int i = 0, v, w, s; i < n; ++i) {
        cin >> v >> w >> s;
        if (s * v > mostv) s = mostv / v; 
        for (int ind = 0; ind < v; ++ind) {
            que.clear();
            for (int jnd = 0; jnd <= (mostv - ind) / v; ++jnd) {
                int res = dp[ind + jnd * v] - jnd * w;
                while (!que.empty() && que.front().first < jnd - s) que.pop_front();
                while (!que.empty() && que.back().second <= res) que.pop_back();
                que.push_back(PII(jnd, res));
                dp[ind + jnd * v] = que.front().second + jnd * w;
            }
        }
    }
    cout << dp[mostv] << endl;
    return 0;
}
