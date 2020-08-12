/*************************************************************************
	> File Name: oj-260.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月01日 星期六 16时32分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char to_10[65] = {0}, to_62[256] = {0};
int ans[10000] = {0};

void init() {
    int id = 0;
    for (char i = '0'; i <= '9'; ++i) {
        to_62[i] = id;
        to_10[id++] = i;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        to_62[i] = id;
        to_10[id++] = i;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        to_62[i] = id;
        to_10[id++] = i;
    }

    return ;
}

int main() {
    int s1, s2;
    string tmp;
    cin >> s1 >> s2 >> tmp;
    int len_tmp = tmp.size(), l = tmp.size(), mmax;

    for (int i = 0; l; ++i) {
        int k = 0;
        for (int j = len_tmp - l; j < len_tmp; j++) {
            k  = k * s1 + to_10[tmp[j]];
            tmp[j] = to_62[k / s2];
            k %= s2;
        }
        ans[i] = to_62[k];
    }

    cout << s1 << " " << tmp << endl << s2  << " ";


    return 0;
}

