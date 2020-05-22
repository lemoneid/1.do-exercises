/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sun 03 May 2020 02:19:28 PM CST
 ************************************************************************/

#include<cstdio>
int main() {
    int a = 321;
    printf("%d\n", ((char *)&a)[0]);
    printf("%d\n", ((char *)&a)[1]);
    printf("%d\n", ((char *)&a)[2]);
    printf("hellow 123 \n ");
    for (int i = 0; i < 4; ++i) 
        printf(" %d = %d\n", i, ((char *)&a)[i]);
    
}

