/*************************************************************************
	> File Name: cd-62.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 11时25分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class {
    int val = -1;
    long long time = 0;
    unordered_map<int, int> mapVal, mapTime;
    public : 
    void put(int key, int val) {
        mapVal[key] = val;
        mapTime[key] = time;
    }

    void get(int key) {
        auto iter = mapVal.find(key);
        if (iter == mapVal.end()) {
            cout << -1 << endl;
            return ;
        }
        int res = iter->second;
        if (mapTime[key] >= this->time) {
            cout << res << endl;
        } else {
            cout << this->val << endl;
        }
    }

    void setAll(int res) {
        this->time += 1;
        this->val = res;
    }

} mmap;
int main() {
    int n;
    cin >> n;
    for (int i = 0, op, x, y; i < n; ++i) {
        cin >> op >> x;
        switch (op) {
            case 1 : 
                cin >> y;
                mmap.put(x, y);
                break;
            case 2 : 
                mmap.get(x);
                break;
            case 3 : 
                mmap.setAll(x);
                break;
        }
    }

    return 0;
}
