/*************************************************************************
	> File Name: test2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月07日 星期三 20时56分33秒
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
    if (nullptr == NULL) {
        cout << "true" << endl;
        cout << typeid(NULL).name() << endl;
        cout << typeid(nullptr).name() << endl;
    }
    char *str = NULL;
    cout << strlen(str) << endl;
    return 0;
}
