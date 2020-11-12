/*************************************************************************
	> File Name: cd-61.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月12日 星期四 10时20分01秒
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
#include <string>
#include <unordered_set>
using namespace std;
int n, area, lef, rig, up, dow;

unordered_set<long long> se;

int main() {
    scanf("%d", &n);
    for (int i = 0, x1,y1,x2,y2; i < n; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (i == 0) {
            lef = x1, rig = x2, dow = y1, up = y2;
        } else {
            lef = min(x1, lef), rig = max(x2, rig);
            dow = min(y1, dow), up = max(y2, up);
        }
        area += (x2 - x1) * (y2 - y1);
        long long s1 = x1 * n + y1;
        long long s2 = x1 * n + y2;
        long long s3 = x2 * n + y1;
        long long s4 = x2 * n + y2;
        if (se.count(s1)) se.erase(s1);
        else se.insert(s1);
        if (se.count(s2)) se.erase(s2);
        else se.insert(s2);
        if (se.count(s3)) se.erase(s3);
        else se.insert(s3);
        if (se.count(s4)) se.erase(s4);
        else se.insert(s4);
    }
    int ans = 0;
    if (se.size() != 4 || 
        !se.count(lef * n +  dow) ||
        !se.count(lef * n + up) ||
        !se.count(rig * n + dow) ||
        !se.count(rig * n + up) 
       ) {
           cout << "No" << endl;
           return 0;
    }
    cout << (area == (rig - lef) * (up - dow) ? "Yes" : "No") << endl;
    return 0;
}

