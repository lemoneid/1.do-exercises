/*************************************************************************
	> File Name: oj-260.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 16时32分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

char sys_ch[65] = {0}, sys_val[256] = {0};

int main() {
    int id = 0;
    for (char i = '0'; i <= '9'; ++i) {
        sys[i] = id;
        sys[id++] = i;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        sys[i] = id;
        sys[id++] = i;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        sys[i] = id;
        sys[id++] = i;
    }

    return 0;
}

