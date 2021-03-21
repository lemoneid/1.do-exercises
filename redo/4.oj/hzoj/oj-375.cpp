/*************************************************************************
	> File Name: oj-375.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 19时52分11秒
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
using namespace std;
#define MAX_N 300
struct Data {
    int sum,  x, id;
} arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        arr[i] = {a + b + c, a, i + 1};
    }
    sort(arr, arr + n, [](const Data &a, const Data &b)  {
        if (a.sum - b.sum) return a.sum > b.sum;
        if (a.x - b.x) return a.x > b.x;
        return a.id < b.id;
    });
    for (int i = 0; i < 5; i++) {
        cout << arr[i].id << " " << arr[i].sum << endl;
    }
    return 0;
}
