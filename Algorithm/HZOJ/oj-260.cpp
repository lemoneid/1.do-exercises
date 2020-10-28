/*************************************************************************
	> File Name: oj-260.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 16时32分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char to_10[256] = {0}, to_62[256] = {0};
char ans[1005], tmp[1005];

void init() {
    int id = 0;
    for (char i = '0'; i <= '9'; ++i) {
        to_10[i] = id;
        to_62[id++] = i;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        to_10[i] = id;
        to_62[id++] = i;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        to_10[i] = id;
        to_62[id++] = i;
    }

    return ;
}

int main() {
    init();
    int s1, s2;
    cin >> s1 >> s2 >> tmp;
    int len = strlen(tmp), l = strlen(tmp), mmax = 0;

    cout << s1 << " " << tmp << endl << s2  << " ";

    for (int i = 0; l; ++i) {
        int k = 0;
        for (int j = len - l; j < len; j++) {
            k  = k * s1 + to_10[tmp[j]];
            tmp[j] = to_62[k / s2];

            k %= s2;
        }
        ans[i] = to_62[k];
        while (l > 0 && tmp[len - l] == '0') {
            --l;
        }
        mmax = i;
    }

    for (int i = mmax; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

