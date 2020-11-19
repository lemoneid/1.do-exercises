/*************************************************************************
	> File Name: cd-90.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 20时41分33秒
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
#define MAX_N 3000

struct Edge {
    int u, v, w, next;
};

struct Node {
    int now, w;
    bool operator<(const Node &b) const {
        return this->w > b.w;
    }
};

priority_queue<Node> que;


int main() {


    return 0;
}
