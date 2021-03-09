/*************************************************************************
	> File Name: 3.myPrintf.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 20时24分33秒
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
#include <stdarg.h>
#include <inttypes.h>

using namespace std;

int int_to_str(char *num, long long  x) {
    int digit = floor(log10(x)) + 1;
    for (int i = digit - 1; i >= 0; i--) {
        num[i] = x % 10 + '0';
        x /= 10;
    }
    num[digit] = '\0';
    return digit;
}

int my_printf(const char *frm, ...) {
    if (!frm) return 0;
    int cnt = 0;
    #define PUTC(ch) putchar(ch), cnt++;
    va_list args;
    va_start(args, frm);
    //cout << frm << endl;
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%' : {
                switch (frm[++i]) {
                    case '%' : {
                        PUTC('%');
                    } break;
                    case 'd' : {
                        int x = va_arg(args, int);
                        uint32_t xx;
                        char num[100];
                        if (x < 0) { PUTC('-'); xx = -x; }
                        else xx = x;
                        int_to_str(num, xx);
                        for (int i = 0; num[i]; i++) PUTC(num[i]);
                    } break;
                    case 's' : {
                        const char *s;
                        s = va_arg(args, const char *);
                        for (int i = 0; s[i]; i++) PUTC(s[i]);
                    } break;
                    default : PUTC(frm[i]); break;
                }
            } break;
        default : PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(args);
    return cnt;
}

int main() {
    char str[100] = "I don't want to be opbitimistic beforehand";
    my_printf("%%%s\n", str);
    printf("INT32_MAX  =  %d\n", INT32_MAX);
    my_printf("INT32_MAX  =  %d\n", INT32_MAX);
    my_printf(" 123123 =  %d\n", 123123);
    printf("INT32_MIN  =  %d\n", INT32_MIN);
    my_printf("INT32_MIN  =  %d\n", INT32_MIN);
    return 0;

    return 0;
}
