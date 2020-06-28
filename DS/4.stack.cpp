/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月21日 星期日 15时31分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int);
int empty(Stack *);
int top(Stack *);
int expand(Stack *);
int push(Stack *, int);
int pop(Stack *);
void output(Stack *);
void clear(Stack *);

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

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
   if (empty(s)) return 0;
    return s->data[s->top];
}

int expand(Stack *s) {
    s->size *= 2;
    s->data = (int *)realloc(s->data, s->size * sizeof(int));
    return 1;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) {
        expand(s);
    }
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    printf("Stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; ++i) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n\n");
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}



