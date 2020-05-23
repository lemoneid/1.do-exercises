/*************************************************************************
	> File Name: 17.pointer.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Thu 21 May 2020 07:54:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define pchar char *
typedef char * ppchar;

#define offset(T, a) ((long)(&(((T *)(NULL))->a)))
struct Data {
    int a;
    double b;
    char c;
};

int main() {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s\n", (char *)(&num2));
    cout << endl;
    //printf("%s\n", (char *)(&num1));
    printf("%ld\n",offset(struct Data, a));
    printf("%ld\n",offset(struct Data, b));
    printf("%ld\n",offset(struct Data, c));
    pchar p, q;
    ppchar a, b;
    printf("p = %lu, q = %lu\n",sizeof(p), sizeof(q));
    printf("p = %lu, q = %lu\n",sizeof(a), sizeof(b));

    return 0;
}

