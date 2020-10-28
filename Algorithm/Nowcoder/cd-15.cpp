/*************************************************************************
	> File Name: cd-15.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月15日 星期二 10时34分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
#define MAX_N 1000000

int arr[MAX_N + 5];
int q[MAX_N + 5];
int head , tail;

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    head = tail = 0;
    for (int i = 0; i < n; ++i) {
        while (tail - head != 0 && arr[q[tail - 1]] < arr[i]) tail--;
        q[tail++] = i;
        if (i < w - 1) continue;
        if (q[head] == i - w) head++;
        i != w - 1 && cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;

}
