#include <haizei/test.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

Function func_arr[100];
int func_cnt = 0;

struct FunctionInfo htest_info;

int RUN_ALL_TESTS() {    
    for (int i = 0; i < func_cnt; ++i) {
        htest_info.success = htest_info.total = 0;
        printf(GREEN_HL("[====RUN====] "));
        printf(RED_HL("%s\n"), func_arr[i].str);
        func_arr[i].func();
        double ans = htest_info.success * 100.0 / htest_info.total;
        printf(GREEN("[ "));
        if (fabs(ans - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), ans);
        } else {
            printf(RED_HL("%6.2lf%%"), ans);
        }
        printf(
            GREEN(" ]")
            " total : %d success : %d\n\n", 
            htest_info.total, 
            htest_info.success
            );
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //将str地址下的字符串拷贝一份
    func_cnt += 1;
    return ;
}
