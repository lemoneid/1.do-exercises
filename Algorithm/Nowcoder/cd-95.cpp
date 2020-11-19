/*************************************************************************
	> File Name: cd-95.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 09时23分28秒
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

char s1[100005], s2[100005];
int f1[300], len1, len2;

int main() {
    scanf("%d%d%s%s", &len1, &len2, s1, s2);
    if (len1 != len2) {
        cout << "false" << endl;
        return 0;
    }
    
    for (int i = 0; i < len1; ++i) {
        f1[s1[i]]++;
    }
    for (int i = 0; i < len2; ++i) {
        f1[s2[i]]--;
        if (f1[s2[i]] < 0) {
            cout << "false" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 256; i++) {
        if (f1[i] != 0) {
            cout << "false" << endl;
            return 0;

        }
    }
    cout << "true" << endl;

    return 0;
}
