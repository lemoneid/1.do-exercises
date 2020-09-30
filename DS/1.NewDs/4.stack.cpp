/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 15时18分47秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack)); 
    s->data = (int *)calloc(n, sizeof(int));
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return -1;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    if (s == NULL) return;
    printf("Stack (%d) : [", s->top + 1);
    for (int i = 0; i <= s->top; ++i) {
        i && printf(",");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = init(max_op);
    int op, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0: 
                printf("pop  from Stack = %d\n", pop(s));
                break;
            case 1:
            case 2:
            case 3:
                printf("push %d to Stack = %d\n", val, push(s, val));
                break;
        }
        output(s);
    }
    clear(s);
    #undef max_op
    return 0;
}
