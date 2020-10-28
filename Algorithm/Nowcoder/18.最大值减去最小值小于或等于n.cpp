/*************************************************************************
	> File Name: 18.最大值减去最小值小于或等于n.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月27日 星期日 19时31分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define MAX_N 1000000

int arr[MAX_N + 5];
int n, num;

int main() {
    cin >> n >> num;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int i = 0, j = 0, res = 0;
    deque <int> qmax, qmin;
    while (i < n) {
        while (j < n) {
            if (qmin.empty() || qmin.back() != j) {
                while (!qmin.empty() && arr[qmin.back()] >= arr[j]) {
                    qmin.pop_back();
                }
                qmin.push_back(j);
                while (!qmax.empty() && arr[qmax.back()] <= arr[j]) {
                    qmax.pop_back();
                }
                qmax.push_back(j);

            }
            if (arr[qmax.front()] - arr[qmin.front()] > num) {
                break;
            }
            ++j;
        }
        res += j - i;
        if (qmin.front() == i) {
            qmin.pop_front();
        }
        if (qmax.front() == i) {
            qmax.pop_front();
        }
        ++i;
    }
    cout << res << endl;
    return 0;
}
