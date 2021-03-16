/*************************************************************************
	> File Name: oj-260.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 20时47分19秒
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
#include <unordered_map>
using namespace std;
#define MAX_N 1000
int to_10[100], to_62[100];

void init() {
    int ind = 0;
    for (int i = '0'; i <= '9'; i++) {
        to_10[i] = ind;
        to_62[ind++] = i;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        to_10[i] = ind;
        to_62[ind++] = i;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        to_10[i] = ind;
        to_62[ind++] = i;
    }
    return ;
}

int main() {
    init();
    for (int i = 0; i < 62; i++) {
        cout << (char)to_62[i] << " " << to_10[to_62[i]] << endl;
    }
    int a, b;
    string num, ans;
    cin >> a >> b >> num;
    return 0;
}
