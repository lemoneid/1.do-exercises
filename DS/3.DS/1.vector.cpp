#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *arr  = (Vector *)malloc(sizeof(Vector));
    arr->data = (int *)malloc(sizeof(int) * n);
    arr->size = n;
    arr->length = 0;
    return arr;
}

bool expand(Vector *arr) {
    int size = arr->size;
    int *new_data = nullptr;
    while (size) {
        new_data = (int *)realloc(arr->data, sizeof(int) * (size + arr->size));
        if (new_data) break;
        size >>=1;
    }
    if (new_data) arr->data = new_data, arr->size += size;
    if (!new_data) return false;
    return true;
}


int insert(Vector *arr, int idx, int val) {
    if (!arr) return 0;
    if (idx < 0 || idx > arr->length) return 0;
    if (arr->length == arr->size) {
        cout << "expand : " << arr->size << endl; 
        bool res = expand(arr);
        if (!res) return 0; 
    }
    for (int i = arr->length - 1; i >= idx; --i) arr->data[i + 1] = arr->data[i];
    arr->data[idx] = val;
    arr->length++;
    return 1;
}

int pop(Vector *arr, int idx) {
    if (!arr) return 0;
    if (idx < 0 || idx >= arr->length) return 0;
    for (int i = idx + 1; i < arr->length; ++i) arr->data[i - 1] = arr->data[i];
    arr->length--;
    return 1;
}

void output(Vector *arr) {
    printf("Vector(%d) = ", arr->length);
    for (int i = 0; i < arr->length; ++i) {
        i && printf(", ");
        printf("%d", arr->data[i]);
    }
    printf("\n");
    return ;
}

void clear(Vector *arr) {
    if (!arr) return ;
    free(arr->data);
    free(arr);
    return ;
}

int main() {
    srand(time(0));
    #define max_op  10
    Vector *arr = init(max_op);
    int op, idx, val;
    for (int i  = 0; i < max_op * 3; ++i) {
        op = rand() % 4;
        idx = rand() % (arr->length + 1);
        val = rand() % 100;
        switch (op) {
            case 0 :
            case 1 :
            case 2 :
            case 3 :
                printf("insert %d at %d = %d\n", val, idx, insert(arr, idx, val));
                break;
            default :
                printf("erase at %d = %d\n", idx, pop(arr, idx));
                break;
        }
        output(arr);
    }


    return 0;
}
