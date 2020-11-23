/*************************************************************************
	> File Name: cd-126.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 21时24分14秒
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

int main() {
    string str;
    int cnt = 0, flag = 1;
    cin >> str;
    for (int i = 0; str[i]; ++i) {
        if (str[i] != '(' && str[i] != ')' || cnt < 0) {
            flag = 0;
            break;
        }
        str[i] == '(' ? cnt++ : cnt--;
    }
    if (cnt != 0) flag = 0;
    cout << (flag == 1 ? "YES" : "NO")<< endl;
    return 0;
}
