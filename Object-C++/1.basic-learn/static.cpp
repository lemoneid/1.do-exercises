/*************************************************************************
	> File Name: static.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月19日 星期四 13时55分57秒
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

static int arr[1024 * 1024] = {1};

void func() {
    static int arr[1024 * 1024] = {1};
    arr[1] = 2;
    cout << arr << ":" << arr[1] << endl;
    return ;
}

int main() {
    arr[1] = 3;
    cout << arr << ":" << arr[1] << endl;
    func();
    cout << arr << ":" << arr[1] << endl;
    return 0;
}
