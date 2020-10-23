#include <haizei/test.h>
#include <string.h>
#include <iostream>
using namespace std;

Function func_arr[100];
int func_cnt = 0;

int RUN_ALL_TESTS() {    
    for (int i = 0; i < func_cnt; ++i) {
        int total = 0, success = 0;
        cout << BLUE << "[====RUN====] " << RESET;
        cout << RED << func_arr[i].str << RESET << endl;
        func_arr[i].func(&total, &success);
        double ans = success * 100.0 / total;
        if (ans == 100.0) cout << MAGENTA << "[  100.00%  ]" << RESET;
        else printf("\033[31m[   %2.2lf%%  ]\033[0m", ans); 
        printf(" total : %d success : %d\n\n", total, success);
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //将str地址下的字符串拷贝一份
    func_cnt += 1;
    return ;
}

void print_false(const char *str, int exp, int act, const char *func, int line) {
    cout << endl;
    printf("\033[1;33m      %s:%d : Failure\n\033[0m", func, line); 
    printf("\033[1;33m            expect : %s\n\033[0m", str);
    printf("\033[1;33m            actual : %d vs %d\n\033[0m", exp, act);
    cout << endl;
}
