/*************************************************************************
	> File Name: 284.超市卖货.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 15时12分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 10000

struct Data {
    int p, d;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b){
    return a.d < b.d;
}
typedef pair<int, int> PII;
set<PII> s;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (s.size() < arr[i].d) { 
            s.insert(PII(arr[i].p, i));
        } else if (arr[i].p > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(arr[i].p, s.begin()->second));
        }
    }
    int sum = 0;
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        sum += iter->first;
    }
    cout << sum << endl;
    return 0;
}
