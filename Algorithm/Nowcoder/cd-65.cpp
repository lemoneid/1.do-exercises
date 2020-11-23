/*************************************************************************
	> File Name: cd-65.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 19时36分47秒
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
#include <list>
using namespace std;

typedef pair<int, int> PII;

class LFUCache {
    public : 
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> fres;
    unordered_map<int, list<int>::iterator> iters;
    int cap, minc;
    LFUCache(int capacity) {
        cap = capacity;
        minc = 0;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        fres[m[key].second].erase(iters[key]);
        ++m[key].second;
        fres[m[key].second].push_back(key);
        iters[key] = --fres[m[key].second].end();
        while (fres[minc].size() == 0) minc++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap < 0) return ;
        if (get(key) != -1) {
            m[key].first = value;
            return ;
        }
        if (m.size() >= cap) {
            m.erase(fres[minc].front());
            iters.erase(fres[minc].front());
            fres[minc].pop_front();
        }
        m[key] = {value, 1};
        minc = 1;
        fres[minc].push_back(key);
        iters[key] = --fres[minc].end();
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    int n, k;
    while (cin >> n >> k) {
        LFUCache cache(k); 
        for (int i = 0, op, a, b; i < n; ++i) {
            cin >> op;
            if (op == 1) {
                cin >> a >> b;
                cache.put(a, b);
            } else {
                cin >> a;
                cout << cache.get(a) << endl;
            }
        }
    }


    return 0;
}
