/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月29日 星期二 18时28分33秒
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
    vec->data = (int *)calloc(n, sizeof(int));
    vec->size = n;
    return vec;
}

int expand(Vector *vec) {
    int extra = vec->size;
    int *p = NULL;
    while (extra) {
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extra));
        if (p) break;
        extra >>= 1;
    }
    if (!p) return 0;
    vec->size += extra;
    vec->data = p;
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
    vec->data[ind] = val;
    vec->length += 1;
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

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

void output(Vector *vec) {
    if (vec == NULL) return ;
    for (int i = 0; i < vec->length; ++i) {
        i && printf(",");
        printf("%d", vec->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 15
    Vector *vec = init(5);
    int op, ind, val;
    for (int i = 0; i < max_op; ++i) {
        op = rand() % 4;
        ind = rand() % (vec->length + 1);
        val = rand() % 100;
        switch (op) {
            case 0 :
            case 1 :
            case 2 : printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
                break;
            case 3 : printf("earse a item at %d from Vector = %d\n", ind, earse(vec, ind));
                break;
        }
        output(vec);
    }


    return 0;
}
