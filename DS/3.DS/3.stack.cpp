#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;


typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)calloc(sizeof(int), size); 
    s->size = size;
    s->top = -1;
    return s;
}

bool expand(Stack *s) {
    int extr_size = s->size;
    int *p = nullptr;
    while (extr_size) {
        p = (int *)realloc(s->data, sizeof(int) *(extr_size + s->size));
        if (p) break;
        extr_size >>= 1;
    }
    if (!p) return false;
    s->data = p;
    s->size += extr_size;
    return true;
}

bool push(Stack *s, int val) {
    if (!s) return false;
    if (s->top + 1 == s->size) {
        if (!expand(s)) return false;
    }
    s->data[++s->top] = val;
    return true;
}

bool empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0x7fffffff;
    return s->data[s->top];
}

bool pop(Stack *s) {
    if (!s) return false;
    if (empty(s)) return false;
    s->top--;
    return true;
}

void  output(Stack *s) {
    printf("Stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; ++i) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = init(1);
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0 :
            case 1 : 
            case 2 : {
                printf("push %d to the Stack = %d\n", val, push(s, val));
            } break;
            case 3 : {
                int temp = top(s);
                printf("pop %d from the Stack = %d\n", temp, pop(s));
            } break;
        }
        output(s);
    }
    #undef max_op
    clear(s);

    return 0;
}
