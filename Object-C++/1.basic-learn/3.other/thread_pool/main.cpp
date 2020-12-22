/*************************************************************************
	> File Name: main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 11时22分16秒
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
#include <thread>
#include "thread_pool.h"
using namespace std;

void func(int x, int &y) {
    y += 2;
    cout << x << " " << y << endl;
}

int main() {
    int x = 2, y = 3;
    worst::Task t(func, ref(x), ref(y));
    t.run();
    cout << x << " " <<  y << endl;
    worst::ThreadPool tp(3);
    tp.start();
    for (int i = 0; i < 10; ++i) {
        tp.add_one_task(func, i, ref(y));
    }
    cout << "add done" << endl;
    this_thread::sleep_for(2s);
    tp.stop();
    return 0;
}
