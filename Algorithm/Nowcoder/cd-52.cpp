/*************************************************************************
	> File Name: cd-52.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 10时47分57秒
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
struct Node {
    int x, h;
    bool isAdd; //true 加入, false 删除
    bool operator<(const Node &b) const {
        if (this->x - b.x) return this->x < b.x;
        if (this->isAdd != b.isAdd) return this->isAdd;
        return false;
    }
};

vector<Node> data;

void build(int n) {
    for (int i = 0, x, y, h; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &h);
        data.push_back((Node){x, h, true});
        data.push_back((Node){y, h, false});
    }
    map<int, int> mapTimes;
    map<int, int> mapValue;
    sort(data.begin(), data.end());
    for (auto cur : data) {
        if (cur.isAdd) {
            if (mapTimes.find(cur.h) == mapTimes.end()) {
                mapTimes[cur.h] = 1;
            } else {
                mapTimes[cur.h]++;
            } 
        } else {
            if (mapTimes[cur.h] == 1) {
                mapTimes.erase(cur.h);
            } else {
                mapTimes[cur.h]--;
            }
        }
        if (mapTimes.empty()) {
            mapValue[cur.x] = 0;
        } else {
            mapValue[cur.x] = mapTimes.rbegin()->first;
        }
    }
    int start = 0, pre = 0;
    for (auto cur : mapValue) {
        int x = cur.first, h = cur.second;
        if (pre != h) {
            if (pre != 0) cout << start << " " << x << " " << pre << endl;
            start = x;
            pre = h;
        }
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    build(n);

    return 0;
}
