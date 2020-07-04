/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月30日 星期二 20时10分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
#define MAX_N 1000
stack <int> num;
stack <char> sym;

int calc(const char *str, int l, int r) {
    for (int i = l; i <= r; ++i) {
        switch(str[i]) {
            case '(' : 
                sym.push('(');
                break;
            case ')' :
                sym.pop();
                break;
            case '+' :
                sym.push('+');
                break;
            case '-' :
                sym.push('-');
            case '*' :
                sym.push('*');
            case '/' :
                sym.push('/');
                break;
            case ' ' :
                break;
        }
    }
}

int main() {
    char str[MAX_N + 5];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%d\n", calc(str, 0, strlen(str) - 1));
    }
    return 0;
}
