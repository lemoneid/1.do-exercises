/*************************************************************************
	> File Name: cd-53-2.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月11日 星期三 09时13分39秒
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
long long dis[MAX_N + 5], oil[MAX_N + 5];
bool res[MAX_N + 5];
int n, init = -1;

#define next(x) ((x + 1) % n)
#define last(x) ((x - 1 + n) % n)

void connect(long long *dis, bool *res, int init, int start) {
    int rest = dis[start];
    int cur = start;
    do {
        if (rest >= 0) {
            res[start] = 1;
            start = last(start);
            rest = dis[start];
        } else {
            res[start] = 0;
            start = last(start);
            rest += dis[start];
        }
    } while (start != init);
    /*
    long cur = start;
        rest = oil[start];
        do
        {
            // 向左找，看上一站能否到达可行点
            if(rest>=0)   // 可达
            {
                ans[cur]=1;
                cur = (cur-1+n)%n;
                rest = oil[cur]; // 油量置成上一站的
            }
            else  // 不可达
            {
                ans[cur] = 0;
                cur = (cur-1+n)%n;  // 也往左找，寻求可能补充油量的站出现
                rest += oil[cur];
            }

        } while (cur != start);
    */
}

void func(long long *dis, bool *res, int init) {
    int start = init , end = next(init);
    int need = 0, rest = 0;
    do {
        if (start != init && start == last(end)) break;    
        if (dis[start] < need) {
            need -= dis[start];
        } else {
            rest += dis[start] - need;
            need = 0;
            while (rest >= 0 && end != start) {
                rest += dis[end];
                end = next(end);
            } 
            if (rest >= 0) {
                res[start] = true;
                connect(dis, res, init, start);
                break;
            }
        }
        start = last(start); 
    } while (start != init);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", oil + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", dis + i);
        dis[i] = oil[i] - dis[i];
        if (dis[i] >= 0) {
            init = i;
        }
    }
    if (init != -1 && n > 1) func(dis, res, init);
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", res[i] ? 1 : 0);
    }
    printf("\n");
    return 0;
}
