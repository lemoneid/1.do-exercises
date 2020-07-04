/*************************************************************************
	> File Name: test-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月01日 星期三 15时25分03秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 50010
using namespace std;

struct Node {
    int s, e;
    int id;
}cows[MAX];

int use[MAX];
vector<Node> vec;

bool cmp (const Node &a, const Node &b){
    return a.s < b.s;
}

void insertOnce(Node &a) {
    int i;
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i].e < a.e) continue;
        break;
    }
    vec.insert(vec.begin() + i, a);
}

int calcLocationt(const Node &a) {
    int x = 0;
    for (int i = 0; vec[i].e < a.s; ++i) {
        if (use[vec[i].id] < use[vec[x].id]) {
            x = i;
        }
    }
    return x;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &cows[i].s, &cows[i].e);
        cows[i].id = i;
    }
    sort(cows, cows + n, cmp);
    for (int i = 0; i < n; ++i) {
        printf("s : %d, e : %d\n", cows[i].s, cows[i].e);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vec.size() && vec[0].e < cows[i].s){
            int x = calcLocationt(cows[i]);
            printf("x : %d\n", x);
            use[cows[i].id] = use[vec[x].id];
            vec.erase(vec.begin() + x);
        }
        else{
            use[cows[i].id] = ++ans;
        }
        printf("use : %d, id : %d\n", use[cows[i].id], cows[i].id);
        insertOnce(cows[i]);
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++){
        printf("%d\n",use[i]);
    }
    return 0;
}
