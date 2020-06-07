/*************************************************************************
	> File Name: 1.Vector.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月06日 星期六 19时50分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
using namespace std;

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
    int extr_size = vec->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size + extr_size));
        if (p) break;
        extr_size /= 2;
    }
    if (extr_size == 0) return 0;
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
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; ++i) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    cout << "Vector = [";
    for (int i = 0; i < vec->length; ++i) {
        !i || cout << ", ";
        cout << vec->data[i];
    }
    cout << "];"<<endl;
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
    for (int i = 0; i < max_op; ++i) {
        int op = rand() % 4;
        int ind = rand() % (vec->length + 3) - 1;
        int val = rand() % 100;
        switch(op) {
            case 1:
            case 2:
            case 0: {
                printf("insert %d at %d to Vector  = %d\n", val, ind, insert(vec, ind ,val));
            } break;
            case 3: {
                printf("erase a itrem at %d at from Vector  = %d\n", ind, erase(vec, ind));
            }break;
        }
        cout << endl;
        output(vec);
    }
    clear(vec);
    #undef max_op
    return 0;
}
