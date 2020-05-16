/*************************************************************************
	> File Name: define.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月14日 星期四 19时06分16秒
 ************************************************************************/

#include <stdio.h>

#define P(a) {\
    printf("%s = %d\n", #a, a);\
}


#define MAX(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
}) 


int main() {
    int a = 9;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(a++, 3));
    return 0;
}
