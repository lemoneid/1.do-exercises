/*************************************************************************
	> File Name: oj-539.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月08日 星期二 20时37分43秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int raw_num[4], calc[4], calc_check[4], calc_cnt;
char ope[3], ope_set[7] = {'+', '-', '*', '/', '&', '|', '^'};
string ans[10000];
int ans_cnt;

int work(int a, int b, char op) {
    if (b == 0 && op  == '/') return -999999999;
    switch (op) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '&' : return a & b;
        case '|' : return a | b;
        case '^' : return a ^ b;
    }
    if (a % b == 0) return a / b;
    return -999999999;
}
void orig (char *temp) {
    for (int i = 0; i < 4; ++i) {
        switch (calc[i]) {
            case 1 : temp[i] = 'A'; break;
            case 10 : temp[i] = 'T'; break;
            case 11 : temp[i] = 'J'; break;
            case 12 : temp[i] = 'Q'; break;
            case 13 : temp[i] = 'K'; break;
            default : temp[i] = calc[i] + '0'; break;
        }
    }
}
void do_calc() {
    char temp[4], t[15];
    if (work(work(work(calc[0], calc[1], ope[0]), calc[2], ope[2]), calc[3], ope[2]) == 24) {
        orig(temp);    
        sprintf(t, "(((%c%c%c)%c%c)%c%c)", temp[0], ope[0], temp[1], ope[1], temp[2], ope[2], temp[3]);
        ans[ans_cnt++] = t;
    }
if ( work(work(calc[0], work(calc[1], calc[2], ope[1]), ope[0]), calc[3], ope[2]) == 24) {
        orig(temp);
        sprintf(t, "((%c%c(%c%c%c))%c%c)", temp[0], ope[0], temp[1], ope[1], temp[2], ope[2], temp[3]);
        ans[ans_cnt] = t;
        ans_cnt++;
    }
    // {a [(b c) d]}
    if ( work(calc[0], work(work(calc[1], calc[2], ope[1]), calc[3], ope[2]), ope[0]) == 24) {
        orig(temp);
        sprintf(t, "(%c%c((%c%c%c)%c%c))", temp[0], ope[0], temp[1], ope[1], temp[2], ope[2], temp[3]);
        ans[ans_cnt] = t;
        ans_cnt++;
    }
    // {a [b (c d)]}
    if ( work(calc[0], work(calc[1], work(calc[2], calc[3], ope[2]), ope[1]), ope[0]) == 24) {
        orig(temp);
        sprintf(t, "(%c%c(%c%c(%c%c%c)))", temp[0], ope[0], temp[1], ope[1], temp[2], ope[2], temp[3]);
        ans[ans_cnt] = t;
        ans_cnt++;
    }
    // {[a b] [c d]}
    if ( work(work(calc[0], calc[1], ope[0]), work(calc[2], calc[3], ope[2]), ope[1]) == 24) {
        orig(temp);
        sprintf(t, "((%c%c%c)%c(%c%c%c))", temp[0], ope[0], temp[1], ope[1], temp[2], ope[2], temp[3]);
        ans[ans_cnt] = t;
        ans_cnt++;
    }
}

void oper() {
    for (int i = 0; i < 7; ++i) {
        ope[0] = ope_set[i];
        for (int j = 0; j < 7; ++j) {
            ope[1] = ope_set[j];
            for (int k = 0; k < 7; ++k) {
                ope[2] = ope_set[k];
                do_calc();
            }
        }
    }
}

void permu(int left) {
    if (left == 0) {
        oper();
        return ;
    } 
    for (int i = 0; i < 4; ++i) {
        if (calc_check[i] == 0) {
            calc[calc_cnt++] = raw_num[i];
            calc_check[i] = 1;
            permu(left - 1);
            calc_cnt--;
        }
    }
}

int main() {
    char a[5];
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
        switch (a[i]) {
            case 'A' : raw_num[i] = 1; break;
            case 'T' : raw_num[i] = 10; break;
            case 'J' : raw_num[i] = 11; break;
            case 'Q' : raw_num[i] = 12; break;
            case 'K' : raw_num[i] = 13; break;
            default : raw_num[i]  = a[i] - '0'; break;

        }
    }
    permu(4);
    sort(ans, ans + ans_cnt);
    cout << ans[0] << endl;
    return 0;
}
