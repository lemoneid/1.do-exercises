/*************************************************************************
	> File Name: cd-121-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 10时42分28秒
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

int record[300];

int main() {
    string s;
    cin >> s;
    for (int i = 0; s[i]; ++i) {
        record[s[i]] = 1;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if (record[i]) {
            printf("%c", i);
        }
    }
    cout << endl;
    return 0;
}
