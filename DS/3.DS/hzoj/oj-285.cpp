/*************************************************************************
	> File Name: oj-285.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 23时26分58秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_M 2000
int nums[MAX_M + 5];
//时间戳, 加负号模拟大顶堆
typedef pair<int, int> PII;

struct BigSet : set<PII> {
public :
    BigSet() : t(0) {}
    void insert(int &a) {
        this->set<PII>::insert(PII(-a, t++));
    }
    void pop() {
        erase(begin());
    }
    int top() {
        return -(begin()->first);
    }

private :
    int t;
};

BigSet s;

void extract(int m) {
    for (int i = m - 1; i >= 0; --i) {
        nums[i] = s.top();
        s.pop();
    }
}

int main() {
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        s.insert(x);
    }
    for (int i = 1; i < n; ++i) {
        extract(m);
        for (int j = 0; j < m; ++j) {
            cin >> x;
            for (int k = 0; k < m; ++k) {
                int y = x + nums[k];
                if (s.size() == m && y >= s.top()) break;
                if (s.size() == m) s.pop();
                s.insert(y);
            }
        }
    }
    extract(m);
    for (int i = 0; i < m; ++i) {
        i && cout << " ";
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
