/*************************************************************************
	> File Name: 13.heap-2.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年01月20日 星期三 12时09分03秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define MAX 100000
typedef struct {
    int num;
    int *p;
} MedianFinder;

MedianFinder *strObj;
/** initialize your data structure here. */

int bigHeap[MAX] = {0}; /* 大根堆 */
int smallHeap[MAX] = {0}; /* 小根堆 */
int bigSize;
int smallSize;

MedianFinder* medianFinderCreate() {
    strObj = malloc(sizeof(MedianFinder));
    strObj->num = 0;
    strObj->p = bigHeap;
    bigSize = 0; 
    smallSize = 0;

    return strObj;
}
/* 根节点在数组的最后
 * 对于大根堆，根节点为最大值,索引在前面
 * 对于小根堆，根节点为最小值，索引在前面
 */
/* 此函数根据堆的定义挪动节点到最上层次，后面的函数再跟下面的层次进行比较 */
/*  对于大根堆：挪动节点到最大的位置，其他节点依次下移 */
/*flag：1 大根堆 -1 小根堆*/
void UpdataHeap(int *heap, int size, int flag) /* 进行堆排序 */
{
    int fatherIdx = size - 1; /* 根节点的索引坐标 */
    int childIdx;
    int originVal = heap[fatherIdx]; /* 最新插入的值 */

    while (fatherIdx >= 0) {
        childIdx = ((fatherIdx + 1) >> 1) - 1; /* 右移一位相当于除以2 */ /* 0->-1 1->0 3->1 4->1 5->2*/ 
        /* SmallHeap: flag = -1,结束循环条件: originVal > heap[childIdx]
         * bigheap: flag = 1, 结束循环条件: originVal < heap[childIdx] 
         * 公共循环条件: childIdx < 0
         */
        if (childIdx < 0 || originVal * flag < heap[childIdx] * flag) { //需要判断是否存在子节点。。
            break;
        }
        heap[fatherIdx] = heap[childIdx];
        fatherIdx = childIdx;
    }
    heap[fatherIdx] = originVal;
    
    return;
}

void BigHeap(int num) /* 插入元素并进行堆排序前的整理工作 */
{
    bigHeap[bigSize++] = num;

    UpdataHeap(bigHeap, bigSize, 1);

    return;
}

void SmallHeap(int num) /* 插入元素并进行堆排序前的整理工作 */
{
    smallHeap[smallSize++] = num;

    UpdataHeap(smallHeap, smallSize, -1);

    return;
}

/*flag：1 大根堆 -1 小根堆*/
void AdjastHead(int index, int heapSize, int *heap, int flag)
{
    int childIdx;
    int middle;
    int max;
    int originVal = heap[index]; //保存节点原始值，这里不要用index，heap中的内容后续会改变！！！

    middle = heapSize >> 1;
/* 比较其左右孩子值的大小，并与其中较小者交换(小根堆) */
/* 对于大根堆，右节点的值要小于左子节点 */
/* 对于小根堆，右节点的值要大于左子节点 */
    while (index < middle) {/* 中间层 */
        childIdx = 2 * index + 1; //左子节点
        max = heap[childIdx]; /* 实际上，对于大根堆是MIN，对于小根堆是MAX */
        if ((childIdx < heapSize - 1) && (flag * max < flag * heap[childIdx + 1])) { //需要判断是否存在右子节点。。
            childIdx = childIdx + 1;
            max = heap[childIdx];  //选择左、右子节点大（小）值
        }

        if (flag * originVal > flag * max) { //满足大（小）根堆条件
            break;
        }

        heap[index] = heap[childIdx];/*  */
        index = childIdx;
    }
    heap[index] = originVal;

    return;
}

void DeleteBigHeapHead()
{
    bigHeap[0] = bigHeap[--bigSize]; //移除head后，将末元素移到head
    AdjastHead(0, bigSize, bigHeap, 1);

    return;
}

void DeleteSmallHeapHead()
{
    smallHeap[0] = smallHeap[--smallSize]; //移除head后，将末元素移到head
    AdjastHead(0, smallSize, smallHeap, -1);

    return;
}

void medianFinderAddNum(MedianFinder* obj, int num) {  
    int i;
    
    /*1、每次增加元素如果大于小根堆最小元素，则加入小根堆；2、如果小根堆个数比大根堆个数多余1个，则将小根堆顶点移到大根堆*/
    if (smallSize == 0 || num > smallHeap[0]) {
        SmallHeap(num);
        if (smallSize > bigSize + 1) {
            BigHeap(smallHeap[0]);
            DeleteSmallHeapHead();
        }
    } else {
        BigHeap(num);
        if (bigSize > smallSize + 1) {
            SmallHeap(bigHeap[0]);
            DeleteBigHeapHead();
        }        
    }

    obj->num = bigSize + smallSize;

    return; 
}

double medianFinderFindMedian(MedianFinder* obj) {
    double temp;

    if (bigSize > smallSize) {
        temp = bigHeap[0];
    } else if (smallSize > bigSize) {
        temp = smallHeap[0];
    } else {
        temp = ((double)(bigHeap[0] + smallHeap[0])) / 2;
    }

    return temp;
}

void medianFinderFree(MedianFinder* obj) {
    free(strObj);
    memset(bigHeap, 0, MAX * sizeof(int));
}
