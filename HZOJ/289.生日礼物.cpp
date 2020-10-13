/*************************************************************************
	> File Name: 289.生日礼物.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月10日 星期六 18时07分47秒
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
#define MAX_N 100000

struct Data {
    int val, id;
} arr[MAX_N + 5];

typedef pair<int, int> PII;
set<PII> s;

int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].val;
        arr[i].val += arr[i - 1].val;
        arr[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        
    }

    return 0;
}
