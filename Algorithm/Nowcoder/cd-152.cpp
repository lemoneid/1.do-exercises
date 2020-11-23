/*************************************************************************
	> File Name: cd-152.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 19时17分52秒
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

priority_queue<int, vector<int>, greater<int>> que;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, val; i < n; ++i) {
        scanf("%d", &val);
        que.push(val);
    }
    for (int i = 0; i < m; ++i) {
        i && printf(" ");
        printf("%d", que.top());
        que.pop();
    }   
    printf("\n");
    return 0;
}
