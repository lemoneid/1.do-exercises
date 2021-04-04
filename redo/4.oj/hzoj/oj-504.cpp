/*************************************************************************
	> File Name: oj-504.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月02日 星期五 20时06分29秒
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
#include <queue>
using namespace std;

int main() {
    string num;
    int cnt = 0;
    cin >> num >> cnt;
    char que[250];
    int head = 0, tail = -1;
    for (int i = 0; num[i]; i++) {
        while (cnt && tail >= 0 && num[i] < que[tail]) tail--, cnt--;
        que[++tail] = num[i];
    }
    while (tail >= head && que[head] == '0') head++;
    for (int i = head; i <= tail - cnt; i++) {
        cout << que[i]; 
    }
    cout << endl;
    return 0;
}
