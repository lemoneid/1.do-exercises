/*************************************************************************
	> File Name: main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 15时08分50秒
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

void func(int x, int &n) {
    n += 2;
    //5次原子操作之间线程不安全
    cout << "func : " << x << " " << n << endl;
}

int main() {
    int n = 123;
    worst::Task t(func, 23, ref(n));
    t.run();
    cout << n << endl;
    worst::ThreadPool tp(5);
    tp.start();
    for (int i = 0; i < 10; ++i) {
        tp.add_one_task(func, i, ref(n));
    }
    cout << "add task done" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "tp stop" << endl;
    tp.stop();
    return 0;
}
