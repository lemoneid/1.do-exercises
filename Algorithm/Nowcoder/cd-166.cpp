/*************************************************************************
	> File Name: cd-165-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 21时06分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include  <inttypes.h>
using namespace std;


int n, root, mmax;
struct Node{
    int data;
    int lchild, rchild;
};

struct returnType {
    int head, size, mmin, mmax;
};

returnType *getReturnType(int head, int size, int mmin, int mmax) {
    returnType *p = (returnType *)malloc(sizeof(returnType));
    p->head = head;
    p->size = size;
    p->mmax = mmax;
    p->mmin = mmin;
    return p;
}

vector<Node> v;
returnType *lastOrder(int root){
    if(root == 0) {
        return getReturnType(0, 0, INT32_MAX, INT32_MIN); 
    }
    returnType *ldata = lastOrder(v[root].lchild);
    returnType *rdata = lastOrder(v[root].rchild);
    int mmin = min(v[root].data, min(ldata->mmin, rdata->mmin));
    int mmax = max(v[root].data, max(ldata->mmax, rdata->mmax));
    int size = max(ldata->size, rdata->size);
    int head = ldata->size > rdata->size ? ldata->head : rdata->head;
    if (ldata->head == v[root].lchild && rdata->head == v[root].rchild && v[root].data > ldata->mmax && v[root].data < rdata->mmin) {
        size = ldata->size + rdata->size + 1;
        head = root;
    }
    free(ldata);
    free(rdata);
    return getReturnType(head, size, mmin, mmax);
}
int main() {
    int n1, l, r, val;
    scanf("%d %d",&n, &root);
    v.resize(n + 1);
    for(int i = 0;i < n; ++i){
        scanf("%d%d%d", &n1, &l, &r);
        v[n1].data = n1;
        v[n1].lchild = l;
        v[n1].rchild = r;
    }
    returnType *p = lastOrder(root);
    cout << p->size << endl;

    //cout << maxlen(root) << endl;
}
