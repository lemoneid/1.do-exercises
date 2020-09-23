/*************************************************************************
	> File Name: oj-386.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月22日 星期二 18时38分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
#define MAX_N 100000

struct node {
    int id;
    int num;
} data[MAX_N + 5];

int m, n;

int cmp(node a, node b) {
    return a.num < b.num;
}

int binary_search(int k) {
    int l  = 0, r = m;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (data[mid].num < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l == m ? 0 : data[l].id;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> data[i].num;
        data[i].id = i + 1;
    }
    sort(data, data + m, cmp);
    int temp, first = 0;
    while (n--) {
        cin >> temp;
        cout << binary_search(temp) << endl;
    }
    return 0;
}
