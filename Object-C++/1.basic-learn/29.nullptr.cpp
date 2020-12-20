/*************************************************************************
	> File Name: 29.nullptr.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 16时13分54秒
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
using namespace std;
/*
 * #ifdef CPP
 * #define NULL 0
 * else 
 * #define NULL (void *)0
 * c中常数0和(void *)0都是空指针常量
 * c++中0是整型,(void *)是空地址
*/
void f(int x) {
    cout << x << endl;
    return ;
}
void f(int *p) {
    cout << p << endl;
    return ;
}
int main() {
    f(nullptr);
    //f(NULL);
    return 0;
}
