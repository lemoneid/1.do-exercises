/*************************************************************************
	> File Name: oj-266.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 13时09分15秒
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
#define MAX_N 1000
char str[MAX_N + 5];

int getFlag(const char *exp, int l, int id) {
    while (id >= l) {
        if (exp[id] == ' ') {
            id--;
            continue;
        }
        if (exp[id] == ')' || isdigit(exp[id])) return 1;
        else return 0;
    }
    return 1;
}

int calc(const char *exp, int l, int r) {
    int flag = 1;
    int prior = 0x3f3f3f3f - 1, temp = 0, pos = -1;
    for (int i = l; i <= r; i++) {
        int cur = 0x3f3f3f3f;
        switch (exp[i]) {
            case '(' : temp += 100; break;
            case ')' : temp -= 100; break;
            case '+' :
            case '-' : 
                flag = getFlag(exp, l, i - 1);
                if (flag) cur = temp + 1;
                break;
            case '*' : 
            case '/' : cur = temp + 2; break;
            case '^' : cur = temp + 3; break;
        }
        if (cur <= prior) {
            pos = i, prior = cur;
        }   
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (exp[i] < '0' || exp[i] > '9') continue;
            num = num * 10 + exp[i] - '0';
        }
        if (!flag) num *= -1;
        return num;
    }
    int ans = 0;
    int a = calc(exp, l, pos - 1);
    int b = calc(exp, pos + 1, r);
    switch (exp[pos]) {
        case '+' : ans = a + b; break;
        case '-' : ans = a - b; break;
        case '*' : ans = a * b; break;
        case '/' : ans = a / b; break;
        case '^' : ans = (int)pow(a, b); break;
    }
    return ans;
}

int main() {
    scanf("%[^\n]s", str);
    int ans = calc(str, 0, strlen(str) - 1);
    cout << ans << endl;
    return 0;
}
