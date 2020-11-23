/*************************************************************************
	> File Name: 9.expr_val.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月02日 星期四 18时40分46秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000

int getFlag (const char *str, int id, int l) {
    while (id >= l) {
        if (str[id] == ' ') {
            id -= 1;
            continue;
        }
        if (str[id] == ')' || isdigit(str[id])) return 1;
        else return 0;
    }
    return 1;
}

int calc(const char *str, int l, int r) {
    int prior = 0x3f3f3f3f - 1, temp = 0, pos = -1; 
    //prior = 0x3f3f3f3f,较大值是为了防止pos不移动,因为当前取得的temp过小
    //cur_prior 与 prior 差1,是为了能够对+-处理
    int flag = 1;
    for (int i = l; i <= r; ++i) {
        int cur_prior = 0x3f3f3f3f;
        switch (str[i]) {
            case '(' : temp += 100; break;
            case ')' : temp -= 100; break;
            case '+' : cur_prior = temp + 1; break;
            case '-' : 
                flag = getFlag(str, i - 1, l);
                if (flag) cur_prior = temp + 1; break;
            case '*' :
            case '/' : cur_prior = temp + 2; break;
            case '^' : cur_prior = temp + 3; break;
            default : break;
        }
        if (cur_prior <= prior) {
            prior  = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (!isdigit(str[i])) continue;
            num = num * 10 + str[i] - '0';
        }
        if (!flag) num *= -1;
        return num;
    }
    int a = calc(str, l, pos - 1);
    int b = calc(str, pos + 1, r);
    int ans =  0;
    switch (str[pos]) {
        case '+' : ans = a + b; break;
        case '-' : ans = a - b; break;
        case '*' : ans = a * b; break;
        case '/' : ans = a / b; break;
        case '^' : ans = (int)pow(a, b); break;
    }
    return ans;
}

int main() {
    char str[MAX_N + 5] = {0};
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%d\n", calc(str, 0, strlen(str) - 1));
    }
    return 0;
}
