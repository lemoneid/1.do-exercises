/*************************************************************************
	> File Name: oj-254.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月30日 星期二 17时32分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 50000

struct Data {
    int id, x, y;
    friend bool operator < (const Data &a, const Data &b)  {
        return a.y > b.y;
    }
} cows[MAX_N + 5];

int num[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    if (a.x - b.x) return a.x < b.x;
    return a.id < b.id;
}

priority_queue <Data> q;

int main() {
    int c, sum = 0;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }
    sort(cows, cows + c, cmp);
    for (int i = 0; i < c; ++i) {
        if (!q.empty() && q.top().y < cows[i].x) {
            num[cows[i].id] = num[q.top().id];
            q.pop();
        } else {
            sum += 1;
            num[cows[i].id] = sum;
        }
        q.push(cows[i]);
    }
    cout << sum << endl;
    for (int i = 0; i < c; ++i) cout << num[i] << endl;
    return 0;
}
