/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月28日 星期一 20时00分32秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>
typedef struct Vector {
    int *data;
    int size, length;

} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    vec->size *= 2;
    int extr_size = vec->size;
    int *p = NULL;
    while (extr_size) {
        p = (int *)realloc(vec->data, sizeof(int) * vec->size);
        if (p) break;
        extr_size >>= 1;
    }
    if (!extr_size) return 0;
    //free(vec->data);
    //realloc 会释放掉 无需free
    vec->data = p;
    vec->size += extr_size;
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
    }
    for (int i = vec->length; i > ind; --i) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->length += 1;
    vec->data[ind] = val;
    return 1;
}

int earse(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; ++i) {
        vec->data[i - 1] = vec->data[i]; 
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    printf("Vector : [");
    for (int i = 0; i < vec->length; ++i) {
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("];\n");
    return ;
}

void clear(Vector *vec) {
    free(vec->data);
    free(vec);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Vector *vec = init(max_op);
    for (int i = 0; i < max_op * 5; ++i) {
        int op = rand() % 6;
        int ind = rand() % (vec->length + 1);
        int val = rand() % 200;
        switch (op) {
            case 0 : {
                printf("earse a iterm at %d from Vector = %d\n", ind, earse(vec, ind));
            } break;
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 : {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
        }
        output(vec);
    }
    clear(vec);
    #undef max_op
    return 0;
}
