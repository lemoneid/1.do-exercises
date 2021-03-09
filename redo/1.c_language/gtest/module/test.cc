#include <module/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int func_cnt = 0;
struct FunctionInfo info;
struct Function func_arr[100];

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        info.total = info.success = 0;
        printf(GREEN("[====RUN====] ") RED(" %s\n"), func_arr[i].str);
        func_arr[i].func();
        double rate = 100.0 *info.success / info.total;
        printf(GREEN("["));
        if (fabs(rate - 100) < 1e-6) {
            printf(GREEN_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("]"));
        printf ("toatil : %d success ; %d\n", info.success, info.total);
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
}
