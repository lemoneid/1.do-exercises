/*************************************************************************
	> File Name: cd-34.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月08日 星期日 19时26分55秒
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

int main() {
    priority_queue<int> que;
    int t, k, n;
    scanf("%d%d", &t, &k);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        for (int j = 0, tmp; j < n; ++j) {
            scanf("%d", &tmp);
            que.push(tmp);
        } 
    }
    for (int i = 0; i < k; ++i) {
        i && printf(" ");
        printf("%d", que.top());
        que.pop();
    }
    printf("\n");
    return 0;
}
