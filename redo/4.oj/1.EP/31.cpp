/*************************************************************************
	> File Name: 31.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月13日 星期六 22时01分16秒
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
#define MAX_N 8
#define MAX_M 200

int w[MAX_N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[MAX_M + 5];

int main() {
    f[0] = 1;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = w[i]; j <= MAX_M; j++) {
            f[j] += f[j - w[i]];
        }
    }
    cout << f[MAX_M] << endl;
    return 0;
}
