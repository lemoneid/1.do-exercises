/*************************************************************************
	> File Name: 2.大小端.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 21时03分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int x = 0x12345678;
    cout << ((*((char *)&x) == 0x12) ? "大端" : "小端" ) << endl;
    return 0;
}
