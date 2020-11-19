/*************************************************************************
	> File Name: cd-102.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 11时56分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

unordered_set<int> se;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        if (se.count(x)) {
            ans = 1;
            break;
        } 
        se.insert(x);
    }
    printf("%s",ans ? "NO" : "YES");
    return 0;
}
