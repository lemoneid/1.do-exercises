/*************************************************************************
	> File Name: main.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 19时22分23秒
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
//#include "logger-haizei.h"
#include "logger.h"
#include "thread_pool.h"
#include <thread>
using namespace std;
void func1 () {
    cout << "1" << "2" << "3" << "4" << "5" << endl;
    return ;
}
void func2 () {
    LOG_INFO <<"1" << "2" << "3" << "4" << "5";
    LOG_DEBUG <<"1" << "2" << "3" << "4" << "5";
    LOG_WARN <<"1" << "2" << "3" << "4" << "5";
    LOG_ERROR <<"1" << "2" << "3" << "4" << "5";
    return ;
}

int main() {
    LOG_SET(worst::LogLevel::DEBUG | worst::LogLevel::ERROR);
    worst::ThreadPool tp(10);
    tp.start();
    for (int i = 1; i <= 20; ++i) {
        tp.add_one_task(func1);
    }
    std::this_thread::sleep_for(2s);
    tp.stop();
    cout << "cout done" << endl;
    tp.start();
    for (int i = 0; i <= 20; ++i) {
        tp.add_one_task(func2);
    }
    std::this_thread::sleep_for(2s);
    return 0;
}
