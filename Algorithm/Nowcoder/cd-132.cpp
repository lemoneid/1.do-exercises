/*************************************************************************
	> File Name: cd-132.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月22日 星期日 11时36分28秒
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
    string s;
    int cnt = 0, n, k;
    cin >> n >> k >> s;
    for (int i = k - 1; i >= 0; i--) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cnt++;
        } else {
            break;
        }
    }
    if (cnt & 1) {
        cout << s[k - 1] << s[k] << endl;
    } else {
        if (s[k] >= 'A' && s[k] <= 'Z') {
            cout << s[k] << s[k + 1] << endl;
        } else {
            cout << s[k] << endl;
        }
    }

    return 0;
}
