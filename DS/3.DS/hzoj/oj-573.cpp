/*************************************************************************
	> File Name: oj-573.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 22时57分47秒
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

struct Data {
    int id, time, period;
    bool operator<(const struct Data & obj) const {
        if (this->time - obj.time) return this->time < obj.time;
        return this->id < obj.id;
    }
};

set<Data> s;

int main() {
    string str;
    int id, time, k;
    while (cin >> str) {
        if (str[0] == '#') break;
        cin >> id >> time;
        s.insert({id, time, time});
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int id = s.begin()->id;
        int time = s.begin()->time;
        int period = s.begin()->period;
        cout << id << endl;
        s.erase(s.begin());
        s.insert({id, time + period, period});
    }

    return 0;
}
