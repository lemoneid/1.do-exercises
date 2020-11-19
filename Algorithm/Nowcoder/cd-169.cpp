/*************************************************************************
	> File Name: cd-169.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月16日 星期一 11时51分59秒
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
using namespace std;

struct Node {
    int data;
    int lchild, rchild;
};
vector<Node> v;
vector<int> arr;
int id = 0;
void inorder(int root) {
    if (root == 0) return;
    inorder(v[root].lchild);
    arr.push_back(v[root].data);
    inorder(v[root].rchild);
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    v.resize(n + 1);
    for (int i = 0, fa, l, r; i < n; ++i) {
        scanf("%d%d%d", &fa, &l, &r);
        v[fa].data = fa;
        v[fa].lchild = l;
        v[fa].rchild = r;
    }
    inorder(root);
    int id = arr.size() - 1;
    while (arr[id] > arr[id - 1]) id--;
    printf("%d ", arr[id]);
    id = 0;
    while (arr[id] < arr[id + 1]) id++;
    printf("%d\n", arr[id]);
    return 0;
}
