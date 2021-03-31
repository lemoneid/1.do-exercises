/*************************************************************************
	> File Name: 29.tree_order.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月30日 星期二 17时26分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;

struct BiNode {
    BiNode() : data(0) {}
    BiNode(int val) : data(val), lchild(NULL), rchild(NULL) {}
    int data;
    BiNode *lchild, *rchild;
};

void behtravel(BiNode* root){
	if (NULL == root)
		return;
	stack<BiNode *> st;
	BiNode * p = root;
	BiNode * pre = NULL;
	while (!st.empty() || p){
		while (p){
			st.push(p);
			p = p->lchild;
		}
		if (!st.empty()){
			p = st.top();
			st.pop();
            if (!p->rchild || pre == p->rchild){
				cout << p->data;
				pre = p;
			}
			else{
				st.push(p);
				p = p->rchild;
			}
		}
	}
}

int main() {
    BiNode *root = new BiNode(1);
    root->lchild = new BiNode(2);
    root->rchild = new BiNode(3);
    behtravel(root);
    return 0;
}
