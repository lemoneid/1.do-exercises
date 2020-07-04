/*************************************************************************
	> File Name: oj-253.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 11时29分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 2500

struct Data {
    int x;
    int y;
} cows[max_n + 5];

int cnt[max_n + 5] = {0};

bool cmp( const Data &a, const Data &b) {
    if (a.y - b.y) return a.y < b.y;
    return a.x > b.x;
}

int main() {
    int c, l;
    cin >> c >> l;
    for (int i = 0; i < c; ++i) {
        cin >> cows[i].x >> cows[i].y;
    }
    for (int i = 0, a, b; i < l; ++i) {
        cin >> a >> b;
        cnt[a] += b;
    }
    sort(cows, cows + c, cmp);
    int ans  = 0;
    for (int i = 0; i < c; ++i) {
        for (int j = cows[i].x; j <= cows[i].y; ++j) {
            if (cnt[j] == 0) continue;
            ans += 1;
            cnt[j] -= 1;
            break;
        }
    }
    cout << ans;
    return 0;
}
