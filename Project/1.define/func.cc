#include <stdio.h>

void funcA(int);
void funcB(int);

void funcB(int n) {
    if (n == 0) return;
    printf("func B: %d\n", n);
    funcA(n - 1);
    return ;
}

void funcA(int n) {
    if (n == 0) return;
    printf("func A: %d\n", n);
    funcB(n - 1);
    return ;
}

int add(int a, int b) {
    return a + b;
}

