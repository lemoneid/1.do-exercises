/*************************************************************************
	> File Name: my_printf.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月09日 星期六 18时09分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int reverse_num(int num, int *temp) {
    int digit = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        ++digit;
    } while(num);
    return digit;
}

int output_num(int num, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        cnt++;
        num /= 10;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0){
                            x = -xx;
                            PUTC('-');
                        } else {
                            x = xx;
                        };
                        int num1 = x / 100000, num2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(num1, &temp1);
                        int digit2 = reverse_num(num2, &temp2);
                        if (num1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                    }
                    break;
                    case 's':
                        const char *str;
                         str = va_arg(arg, const char *);
                    for (int i = 0; str[i]; ++i) {
                        PUTC(str[i]);
                    }
                }
            } break;
        
            default : PUTC(frm[i]); break;
        }
    }
    va_end(arg);
    #undef PUTC
    return cnt;
}

int main() {
    char str[100] = "I don't want to be opbitimistic beforehand";
    my_printf("int (-123) =  %d\n", -123);
    printf("INT32_MAX  =  %d\n", INT32_MAX);
    my_printf("INT32_MAX  =  %d\n", INT32_MAX);
    printf("INT32_MIN  =  %d\n", INT32_MIN);
    my_printf("INT32_MIN  =  %d\n", INT32_MIN);
    my_printf("%s\n", str);
    return 0;
}
