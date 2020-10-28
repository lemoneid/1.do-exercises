/*************************************************************************
	> File Name: temp.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月15日 星期四 19时18分56秒
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

int n, x, num[45], ans[2][2100000], cnt[2], sum;

void func(int mark, int s, int e) {
    if (sum > x) return ;
    ans[mark][cnt[mark]++] = sum;
    for (int i = s; i < e; ++i) {
        sum += num[i];
        func(mark, i + 1, e);
        sum -= num[i];
    }
}

int main() {
    while (cin >> n >> x) {
        cnt[0] = cnt[1] = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        func(0, 0, n / 2);
        func(1, n / 2, n);
        int flag = 0;
        sort(ans[1], ans[1] + cnt[1]);
        for (int i = 0; i < cnt[0]; ++i) {
            int l = 0, r = cnt[1] - 1, t = x - ans[0][i];
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (t == ans[1][mid]) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
                if (t < ans[1][mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
