/*************************************************************************
	> File Name: prime_thread.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 13时35分50秒
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
#include "thread_pool.h"
using namespace std;


int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void prime_cnt(int &ans, int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        cnt += is_prime(i);
    }
    ans += cnt;
    return ;
}

int main() {
    int cnt = 0;
    worst::ThreadPool tp(5);
    tp.start();
    for (int i = 1; i <= 10; ++i) {
        tp.add_one_task(prime_cnt, ref(cnt), (i - 1) * 10000 + 1, i * 10000);
    }
    tp.stop_until_empty();
    tp.stop();
    cout << cnt << endl;
    return 0;
}
