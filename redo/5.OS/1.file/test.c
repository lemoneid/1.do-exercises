/*************************************************************************
	> File Name: test.c
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月14日 星期日 19时45分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <regex.h>

int main() {
    regex_t c_pattern;
    int result;
    if (regcomp(&c_pattern, "[A-Za-z0-9_]*\\.py", 0)) {
        printf("Compilation failed!\n");
        return -1;
    }
    result = regexec(&c_pattern, filename, 0, NULL, 0);
    if (!result) {

    } else if (result != REG_NOMATCH) {
        printf("Error matching!\n");
        return -1;
    }
    int code_file = open(filename, O_WRONLY|O_TRUNC);
    if (code_file == -1) {
        printf("Failed to open!\n");
        return -1;
    }
    write(code_file, to_write, write_length);
    return 0;
}

