#include <cstdio>
#include <cstdlib>
typedef struct Heap {
    int *data;
    int n, size;
} Heap;

void expandHeap(Heap *h) {
    int extra = h->size;
    int *p = NULL;
    while (extra) {
        p = (int *)realloc(h->data, (extra + h->size)*sizeof(int));
        if ( p != NULL) break;
        extra >>= 1;
    }
 //   h->data = realloc(h->data, (2 * h->size)*sizeof(int));
   // h->size *= 2;
   if (p) {
       h->size += extra;
       h->data = p;
   }
    return ;
}

#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp; \
}

#define pushHeap(h, val, comp) {\
    if (h->size == h->n + 1) {\
        expandHeap(h);\
    }\
    h->data[++(h->n)] = val;\
    int ind = h->n;\
    while (ind != 1 && h->data[ind] comp h->data[ind>>1]) {\
       swap(h->data[ind], h->data[ind >> 1]);\
        ind >>= 1;\
    }\
} 

#define popHeap(h, comp) do {\
    if (h->n == 0) break;\
    h->data[1] = h->data[h->n--];\
    int ind = 1;\
    while (ind << 1 <= h->n) {\
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;\
        if (h->data[l] comp h->data[tmp]) tmp = l;\
        if (r <= h->n && h->data[r] comp h->data[ind]) tmp = r;\
        if (tmp == ind) break;\
        swap(h->data[tmp], h->data[ind]);\
        ind = tmp;\
    }\
} while(0);

Heap *createHeap() {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = 100;
    h->data = (int *)malloc(sizeof(int) * h->size);
    h->n = 0;
    return h;
}

void clearHeap(Heap *h) {
    if (h == NULL) return;
    free(h->data);
    free(h);
    return; 
}

typedef struct {
    Heap *min_heap, *max_heap;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder *m = (MedianFinder*)malloc(sizeof(MedianFinder));
    m->min_heap = createHeap();
    m->max_heap = createHeap();
    return m;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->min_heap->n == 0 || num >= obj->min_heap->data[1]) {
        pushHeap(obj->min_heap, num, <);
    } else {
        pushHeap(obj->max_heap, num, >);
    }
    if (obj->min_heap->n - obj->max_heap->n == 2) {
        pushHeap(obj->max_heap, obj->min_heap->data[1], >);
        popHeap(obj->min_heap, <);
    }
    if (obj->max_heap->n - obj->min_heap->n == 2) {
        pushHeap(obj->min_heap, obj->max_heap->data[1], <);
        popHeap(obj->max_heap, >);
    }
    return ;
}

double medianFinderFindMedian(MedianFinder* obj) {
    switch (obj->min_heap->n - obj->max_heap->n) {
        case -1 : return obj->max_heap->data[1];
        case 0 : return 1.0 * (obj->max_heap->data[1] + obj->min_heap->data[1]) / 2.0;
        case 1 : return obj->min_heap->data[1];
    }
    return 0.0;
}

void medianFinderFree(MedianFinder* obj) {
   if (obj == NULL) return ;
    clearHeap(obj->min_heap);
    clearHeap(obj->max_heap);
    free(obj);
    return ;
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
