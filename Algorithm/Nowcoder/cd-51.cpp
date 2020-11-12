/*************************************************************************
	> File Name: cd-51.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 11时19分21秒
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
#define MAX_N 100000

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> que;
    long long n;
    scanf("%lld", &n);
    for (long long i = 0, tmp; i < n; ++i) {
        scanf("%lld", &tmp);
        que.push(tmp);
    }
    long long ans = 0;
    while (que.size() != 1) {
        long long sum  = que.top();
        que.pop();
        sum += que.top();
        que.pop();
        que.push(sum);
        ans += sum;
    }
    printf("%lld\n", ans);
    return 0;
}
