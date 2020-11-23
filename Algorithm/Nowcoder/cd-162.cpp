/*************************************************************************
	> File Name: cd-162.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 20时03分09秒
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

int GetTreeHeight(int **tree,int m,int l)
{
    if(m==0)
        return l;
    else
    {
        int a=GetTreeHeight(tree,tree[m][0],l+1)>=GetTreeHeight(tree,tree[m][1],l+1)?GetTreeHeight(tree,tree[m][0],l+1):GetTreeHeight(tree,tree[m][1],l+1);
        return a;
    }
}

void GetEdge(int **tree,int m,int l,int **edge)
{
    if(m==0)
        return;
    if(edge[l][0]==0)
        edge[l][0]=m;
    edge[l][1]=m;
    GetEdge(tree,tree[m][0],l+1,edge);
    GetEdge(tree,tree[m][1],l+1,edge);
}

void PrintLeaf(int **tree,int m,int **edge,int l)
{
    if(m==0)
        return;
    if(tree[m][0]==0&&tree[m][1]==0&&m!=edge[l][0]&&m!=edge[l][1])
        printf("%d ",m);
    PrintLeaf(tree,tree[m][0],edge,l+1);
    PrintLeaf(tree,tree[m][1],edge,l+1);
}

void PrintBorder1(int **tree,int m)
{
    int height;
    height=GetTreeHeight(tree,m,0);
    int **edge=new int*[height];
    for(int i=0;i<height;i++)
    {
        edge[i]=new int[2];
        edge[i][0]=0;
        edge[i][1]=0;
    }
    GetEdge(tree,m,0,edge);
    for(int i=0;i<height;i++)
    {
        printf("%d ",edge[i][0]);
    }
    PrintLeaf(tree,m,edge,0);
    for(int i=height-1;i>0;i--)
    {
        if(edge[i][0]!=edge[i][1])
            printf("%d ",edge[i][1]);
    }
}

void PrintBorder2(int **tree,int m)
{
    stack<int> stk_help;
    printf("%d ",m);
    int cur=m;
    int border=m;
    while(!stk_help.empty()||cur!=0)
    {
        while(cur!=0)
        {
            if(cur==tree[border][0]||cur==tree[border][1]||(0==tree[cur][0]&&0==tree[cur][1]))
            {
                printf("%d ",cur);
                border=cur;
            }
            stk_help.push(cur);
            cur=tree[cur][0];
        }
        cur=tree[stk_help.top()][1];
        stk_help.pop();
    }
    cur=tree[m][1];
    while(tree[cur][0]!=0||tree[cur][1]!=0)
    {
        stk_help.push(cur);
        if(tree[cur][1]!=0)
            cur=tree[cur][1];
        else
            cur=tree[cur][0];
    }
    while(!stk_help.empty())
    {
        printf("%d ",stk_help.top());
        stk_help.pop();
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int **tree=new int*[n];
    for(int i=0;i<n;i++)
    {
        int r;
        scanf("%d",&r);
        tree[r]=new int[2];
        scanf("%d %d",tree[r],tree[r]+1);
    }
    PrintBorder1(tree,m);
    printf("\n");
    PrintBorder2(tree,m);
    return 0;
}
