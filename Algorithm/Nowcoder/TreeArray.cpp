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
using namespace std;
int n, root, mmax;
struct node{
    int data;
    int lchild, rchild;
};
vector<node> v;
void dfs(int root, int depth, int sum, int &mmaxdepth){
    if(root == 0)
        return;
    sum = sum + v[root].data;
    if(sum == mmax && depth > mmaxdepth)
    {
        mmaxdepth = depth;
    }
    dfs(v[root].lchild, depth+1, sum, mmaxdepth);
    dfs(v[root].rchild, depth+1, sum, mmaxdepth);
}
int maxlen( int root){
    if(root == 0){
        return 0;
    }
    int m0 = 0,ml = 0,mr = 0;
    dfs(root, 1, 0, m0);
    ml = maxlen(v[root].lchild);
    mr = maxlen(v[root].rchild);
    return max(m0, max(ml, mr));
}
int main() {
    int n1, l, r, val;
    scanf("%d %d",&n,&root);
    v.resize(n + 1);
    for(int i = 0;i < n; ++i){
        scanf("%d%d%d%d", &n1, &l, &r, &val);
        v[n1].data = val;
        v[n1].lchild = l;
        v[n1].rchild = r;
    }
    scanf("%d", &mmax);
    cout << maxlen(root) << endl;
}
