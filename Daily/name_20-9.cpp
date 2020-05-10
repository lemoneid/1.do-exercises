/*************************************************************************
	> File Name: name_20-9.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月09日 星期六 14时46分00秒
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string.h>
using namespace std;
#define max_n 16

char name[max_n][20] = {"杨宇晨", "严志伟", "何进康", "刘雨欣", "吴根胜",
                        "周缘", "张晓宇", "张本超", "张芝涵", "张雨桐",
                        "曹政", "樊帅朋", "艾艺", "郑佳伟", "魏家锐", "黄啸峰"
    };
int mark[max_n] = {0};
void output_name(int n) {
    if(n > 16) {
        printf("ERROR\n");
        return ;
    }
    srand(time(0));
    int index;
    for (int i = 0; i < n; ) {
        index = rand() % max_n;
        if (mark[index]) continue;
        printf("%s ", name[index]);
        ++i;
        mark[index] = 1;
    }
    printf("\n");
    return ;
}

int str_to_int(char str[]) {
    int n = strlen(str);
    int sum =  0, i = 0;
    while(n--) {
        sum *= 10;
        sum += str[i++] - '0';
    }
    return sum;
}

int main(int argc, char *argv[]) {
    char str[3] = {0};
    if (argc < 2) {
        output_name(1);
    } else {
        sprintf(str, "%s", argv[1]);
        output_name((str_to_int(str)));
    }
    return 0;
}
