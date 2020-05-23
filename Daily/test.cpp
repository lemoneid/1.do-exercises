/*************************************************************************
    > File Name: test.cpp
    > Author: weier 
    > Mail: 1931248856@qq.com 
    > Created Time: Sun 03 May 2020 02:19:28 PM CST
 ************************************************************************/

#include<cstdio>
<<<<<<< HEAD
int main() {
    
=======
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Data {
    int x, y;
} Data;

int main() {
    int  *p1;
    char *p2;
    printf("%p %p\n", p1, p1 + 1);
    printf("%p %p\n", p2, p2 + 1);
    Data a[2] = { {0,1}, {2,3} };
    Data *p = a;
    printf("%d\n", (*(a + 1)).x);
    printf("%d\n", (*(p + 1)).x);
    printf("%d\n", (p + 1)->x);
    printf("%d\n", (a + 1)->x);
    printf("%d\n", p[1].x);
>>>>>>> b629448bdd4ef9bf9d3b1ae865ab176f2068303f
}

